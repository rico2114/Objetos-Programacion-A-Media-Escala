//
// Created by Sebastían on 4/09/2016.
//

#ifndef PROYECTO_IMAGE_H
#define PROYECTO_IMAGE_H

#include <iostream>

using std::cout;
using std::endl;
class Image {
    /**
     * Represents the image width
     */
    int width;

    /**
     * Represents the image height
     */
    int height;

    /**
     * Represents the pixels data
     */
    int * pixels;

public:

    /**
     * Constructs an image based on the width and the height
     * @param width the width of the image
     * @param height    the height of the image
     */
    Image(int width, int height) {
        this->width = width;
        this->height = height;
        this->pixels = new int[width * height];
    }

    /**
     * Copies the image array into a new instance
     * @return  a new image instance
     */
    Image * copy();

    /**
     * Sub images a desired image (crops it)
     * @param initialX  the initial crop starting point (x based)
     * @param initialY  the initial crop starting point (y based)
     * @param width the desired width of the new image
     * @param height    the desired height of the image
     * @return  a new image instance
     */
    Image * subImage(int initialX, int initialY, int width, int height);

    /**
     * Converts two dimensional points into a 1D point
     * @param x the x coordinate
     * @param y the y coordinate
     * @return  the point coordinate in 1D
     */
    int convertPoints(int x, int y);

    /**
     * Sets the pixel <code> id </code> of the image on a desired color (shifted back into a an int format)
     * @param id    the index of the pixel
     * @param red   the red intensity
     * @param green the green intensity
     * @param blue  the blue intensity
     */
    void setPixel(int id, int red, int green, int blue);

    /**
     * Sets the pixel <code> id </code> of the desired image to a desired color
     * @param id    the index of the pixel
     * @param color the color
     */
    void setPixel(int id, int color);

    /**
     * Converts the image pixels into black and white based on a threeshold
     * @param delta the threeshold
     */
    void convertToBlackAndWhite(int delta);

    /**
     * Gets the red intesity of the pixel
     * @param id    the pixel id
     * @return  the intensity of the pixel
     */
    int getRed(int id);

    /**
     * Gets the green intesity of the pixel
     * @param id    the pixel id
     * @return  the intensity of the pixel
     */
    int getGreen(int id);

    /**
     * Gets the blue intesity of the pixel
     * @param id    the pixel id
     * @return  the intensity of the pixel
     */
    int getBlue(int id);

    /**
     * Checks if whether or not the desired pixel is white
     * @param id    the pixel id
     * @return  true if the pixel is white false if not
     */
    bool isWhite(int id);

    /**
     * Gets the pixel color information masked in an int
     * @param id    the pixel id
     * @return  the pixel color
     */
    int getPixel(int id);

    /**
     * Gets the maximum pixel color
     * @return  the maximum pixel color
     */
    int getMaximumPixel();

    /**
     * Gets the width of the image
     * @return the width
     */
    int getWidth();

    /**
     * Gets the height of the image
     * @return  the height
     */
    int getHeight();
};


#endif //PROYECTO_IMAGE_H
