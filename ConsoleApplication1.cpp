// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 

using namespace std;

void simulateColorBlindness(cv::Mat& image, const string& blindnessType, float intensity) {
    if (blindnessType == "p" || blindnessType == "d" || blindnessType == "t") {
        int rows = image.rows;
        int cols = image.cols;

       
        intensity = std::max(0.0f, std::min(intensity, 1.0f));

        for (int y = 0; y < rows; ++y) {
            for (int x = 0; x < cols; ++x) {

                cv::Vec3b& pixel = image.at<cv::Vec3b>(y, x);
                int B = pixel[0];
                int G = pixel[1];
                int R = pixel[2];

                if (blindnessType == "p") {
                    pixel[1] = (int)((1.0 - intensity) * pixel[1] + intensity * (0.567 * R + 0.433 * B));
                    pixel[2] = (int)((1.0 - intensity) * pixel[2] + intensity * (0.817 * R + 0.183 * B));
                }
                else if (blindnessType == "d") {
                    pixel[1] = (int)((1.0 - intensity) * pixel[1] + intensity * (0.625 * R + 0.375 * B));
                    pixel[2] = (int)((1.0 - intensity) * pixel[2] + intensity * (0.7 * R + 0.3 * B));
                }
                else if (blindnessType == "t") {
                    pixel[0] = (int)((1.0 - intensity) * pixel[0] + intensity * (0.95 * R + 0.05 * G));
                    pixel[2] = (int)((1.0 - intensity) * pixel[2] + intensity * (0.433 * R + 0.567 * G));
                }
            }
        }
    }
    else if (blindnessType == "bw") {
        cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
        cv::cvtColor(image, image, cv::COLOR_GRAY2BGR);
    }
}

int main() {
    string inputFilename;
    cout << "Enter the location of the image file (JPEG format): ";
    cin >> inputFilename;
    cv::Mat image = cv::imread(inputFilename);
    if (image.empty()) {
        std::cerr << "Error: Failed to load image " << inputFilename << std::endl;
        return EXIT_FAILURE;
    }
    string blindnessType;
    cout << "Choose the type of color blindness (p for protanopia, d for deuteranopia, t for tritanopia, or bw for black_white): ";
    cin >> blindnessType;
    float intensity = 1.0f; // Default intensity
    if (blindnessType != "bw") {
        cout << "Enter the intensity adjustment scale (0 to 1): ";
        cin >> intensity;
    }
    simulateColorBlindness(image, blindnessType, intensity);
    string outputFilename = "adjusted_image.jpg";
    cv::imwrite(outputFilename, image);

    cout << "Color blindness simulation completed. Adjusted image saved as " << outputFilename << endl;
    cv::imshow("Adjusted Image", image);
    cv::waitKey(0);

    return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
