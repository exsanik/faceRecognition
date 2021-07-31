#include "Libs.h"


int main(int argc, char **argv)
{
	HideConsole();
	bool wrong = false;
	for(int i = 1; i < argc; i++)
		if (strstr(argv[i], ".jpg") == NULL)
		{
			wrong = true;
			break;
		}

	if (argc >= 3 && !wrong)
	{
		faceRecognition fc1;
		fc1.setImg(argv, argc);
		fc1.recognizeFace();
	}

	return 0;
}