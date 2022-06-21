// pixels.cpp: 
// using SFML to load a file, manipulate its pixels, write it to disk


// g++ -o pixels pixels.cpp -lsfml-graphics -lsfml-window

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "FibLFSR.hpp"



// Transforms image using FibLFSR
void transform(sf::Image& image, FibLFSR* seed)
{		
	    sf::Uint8 redSubstitute, greenSubstitute, blueSubstitute;

    /* image width */
    int width = image.getSize().x;
    /* image height */
    int height = image.getSize().y;

    int newInt = 0;
	int x = 0;
	int y = 0;

    // for each pixel (x, y) extract the red, green and blue
    for( x = 0; x != width; x++){
        for(y = 0; y != height ; y++ ){

            sf::Color pixel = image.getPixel(x,y);

            // get red component 
            newInt = seed->generate(30);
            redSubstitute = pixel.r ^ ((sf::Uint8)newInt);

            // get green component 
            newInt = seed->generate(30);
            greenSubstitute = pixel.g ^ ((sf::Uint8)newInt);

            // get blue component 
            newInt = seed->generate(30);
            blueSubstitute = pixel.b ^ ((sf::Uint8)newInt);

            // Create new Color 
            sf::Color newColor(redSubstitute, greenSubstitute, blueSubstitute);
			
            // Set new color 
            image.setPixel(x, y, newColor);
        }
    }
}


// Display an encrypted copy of the picture, using the LFSR to do the encryption

int main()
{
	//input source
	string originalFile;
	
	//output source
	string encryptionFile;

	//seed
	string seed;
	
	
	//read files
	cout <<"Please enter OriginalFile DesiredOutput Seed \n";
	cin >> originalFile >> encryptionFile >> seed;

	
 	// seed 
    FibLFSR fibSeed(seed);	
	
	// Create Windows
	sf::RenderWindow window1(sf::VideoMode(591,827), "Original Image");
    sf::RenderWindow window2(sf::VideoMode(591,827), "Encrypted Image");


	//org image and texture
	sf::Image image;
	image.loadFromFile(originalFile);

		//make sure image opens
		if (!image.loadFromFile(originalFile))
			{
				return -1;
			}

	// p is a pixelimage.getPixel(x, y);
	sf::Color p;

	//where Transform Belongs
	transform(image, &fibSeed);



	//encrypted image and sprite
	 sf::Texture imageEncryption;
    imageEncryption.loadFromFile(encryptionFile);

	sf::Sprite imageBgEncryption;
    imageBgEncryption.setTexture(imageEncryption);

	
	sf::Texture texture;
	texture.loadFromImage(image);

	sf::Sprite sprite;
	sprite.setTexture(texture);

	//event loop
	while (window1.isOpen() && window2.isOpen()) {
		sf::Event event;
		while (window1.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window1.close();
		}
		while (window2.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window2.close();
		}
		window1.clear();
		window1.draw(sprite);
		window1.display();

		window2.clear();
		window2.draw(imageBgEncryption);
		window2.display();
}

	// fredm: saving a PNG segfaults for me, though it does properly
	//   write the file
	if (!image.saveToFile(encryptionFile))
		return -1;

	return 0;
}