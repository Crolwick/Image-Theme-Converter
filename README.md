# Image Theme Converter

## Project Description
### Orginal Purpose
The purpose of this project is to convert an image into shades of grey/gray color theme. I orginally decided to creaste this because I wanted to turn any images into the theme of my favorite video game, Nier Automata. I wanted to use these converted images to customize my computer around this theme. However, I realize that I may want to convert into other colored themes in the future, and allowed an option to change these colors into different ones.

### Technologies Used
I decided to create a small program to do this conversion process, and decided to use OpenCV. The reasoning behind this instead of using something like photoshop, is to have a way to quickly have this done, and automate it without having to do a bunch of photoshop or similar operations.

### Challenges Faced
Several challenges I faced was figuring out how to change a certain color in an image into the ones I wanted to use. In the end, I managed to figure it out, and finish the program. I will say that the ranges I read for colors to convert is pretty basic, and hope to improve on this in the future to make a more precise identification of colors and conversions. I also plan to possibly make a UI for the program, so the program would be easier to use for everyone. One last thing I plan to improve upon is to maybe try and make the program faster.

## Usage
### Getting Started
First, open the sln file into visual studio or a text editor of your choice. Locate in the main.cpp, the string path variable, and follow the rules from there.
It will tell you to change the file path to whatever file path your image is at.

### Changing the colors
If you would like to change the theme of colors, the locate the functions.h header file. In there, at the very top, the first variable array called color are the colors you should change. They are set in BGR format, and listed lightest to darkest initally. This follows the colors of the rainbow; lightest = red, darkest = purple/magenta.

## License
Feel free to use this program for whatever needs is necessary. Any help is appreciated.
