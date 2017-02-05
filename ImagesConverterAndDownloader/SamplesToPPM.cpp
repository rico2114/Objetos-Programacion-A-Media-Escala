#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using std::ifstream;
using std::string;
using std::ofstream;
using std::cout;
using std::endl;

void saveImage(string path, int module) {
	int width = 28;
	int height = 28;
	int imageSize = width * height;
	int samples = 1000;
	ifstream stream(path, std::ios::binary);


	int offset = 0;
	int red;
	int green;
	int blue;
	unsigned char colorData[3];

	int crop = 10;
	for (int i = 0; i < samples; i ++) {
		string main ="C:/Users/Usuario/Desktop/Componentes Red/";
		string s = "image";
		s.append(SSTR(module));
		s.append("_");
		s.append(SSTR(i));
		s.append(".ppm");
		main.append(s);

		cout << main << endl;
		ofstream out(main, std::ios::binary);

	    out << "P6\n" << crop << " " << crop << "\n255\n";
	    unsigned char rr, gg, bb;
	    for (int y = 0; y < height; y ++) {
	    	for (int x = 0; x < width; x ++) {
	    		stream.read(reinterpret_cast<char *>(colorData), 3);
	    		if (y >= 0 && y < crop && x >= 0 && x < crop) {
					rr = static_cast<unsigned char>((colorData[0] & 0xff));
			    	gg = static_cast<unsigned char>((colorData[1] & 0xff));
			    	bb = static_cast<unsigned char>((colorData[2] & 0xff));

			    	out << rr << gg << bb;
		    	}
	    	}	
	    }
		out.close();
	}	
	stream.close();
 }


int main() {
	// Save data into ppm format
	/*for (int i = 0; i <= 9; i++) {
		string main ="C:/Users/Usuario/Desktop/Componentes Red/";
		string s = "data";
		s.append(SSTR(i));
		main.append(s);

		saveImage(main, i);
	}*/
	// Cluster the unvalid files
	for (int i = 0; i <= 9; i ++) {
		for (int x = 0; x < 1000; x ++) {
			string dir = "C:/Users/Usuario/Desktop/Componentes Red/";
			dir.append("image");
			dir.append(SSTR(i));
			dir.append("_");
			dir.append(SSTR(x));
			dir.append(".ppm");

			ifstream stream;
    		stream.open(dir, std::ios::binary);

			string header = "";
    		stream >> header;

    		int width, height, unused;
    		stream >> width >> height >> unused;
    		stream.ignore(256, '\n');

    		unsigned char colorData[3];
    		int red, green, blue;
    		bool hasDiffThanBlack = false;


    		for (int xx = 0; xx < width * height; ++ xx) {
		        stream.read(reinterpret_cast<char *>(colorData), 3);
		        red = colorData[0];
		        green = colorData[1];
		        blue = colorData[2];

		        int col = ((blue & 0xff) << 16)| ((green & 0xff) << 8) | (red & 0xff);
		        if (col != 0) {
		        	hasDiffThanBlack = true;
		        	break;
		        }
		    }

		    stream.close();

		    if (hasDiffThanBlack == false) {
		    	cout << "SHOULD REMOVE: " << dir << endl;
		    	cout << (remove(dir.c_str())) << endl;
		    }
		}
	}
	return 0;
}