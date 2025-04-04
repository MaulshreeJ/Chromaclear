# ChromaClear : The Color Kind Sketch Wizard

ChromaClear is a C++ application that simulates different types of color blindness on images using OpenCV. It allows users to visualize how images appear to individuals with various types of color vision deficiencies.

## Features
- Simulates **Protanopia**, **Deuteranopia**, **Tritanopia**, and **Black & White (Grayscale)** vision.
- Adjustable intensity for color blindness effects.
- Supports JPEG image input and output.

## Installation
### Prerequisites
- C++ compiler (e.g., MinGW for Windows or GCC for Linux/Mac)
- OpenCV library installed

### Setup
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/ChromaClear.git
   cd ChromaClear
   ```
2. Ensure OpenCV is installed and linked properly.
3. Compile the code:
   ```sh
   g++ -o chromaclear ConsoleApplication1.cpp `pkg-config --cflags --libs opencv4`
   ```
4. Run the program:
   ```sh
   ./chromaclear
   ```

## How It Works
This project was developed based on research into color vision deficiencies. The simulation is achieved using matrix transformations that approximate how light is perceived by individuals with different types of color blindness. The formulas used for conversion are derived from established models in vision science.

## Usage
1. Run the program and enter the image file path when prompted.
2. Select the type of color blindness to simulate:
   - `p` for Protanopia
   - `d` for Deuteranopia
   - `t` for Tritanopia
   - `bw` for Black & White
3. If applicable, set the intensity (between 0 and 1).
4. The modified image will be saved as `adjusted_image.jpg`.

## License
This project is open-source and available under the MIT License.

## Author
[MaulshreeJ](https://github.com/MaulshreeJ)
