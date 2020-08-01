#include <iostream>
#include <fstream>
#include <string>
#include <queue>

const std::string wordsListFilename = "WordsList.txt";
const std::string inputFilename = "InputFile.txt";
const std::string moddedFilename = "ModifiedFile.txt";
const std::string DELIMITER_STR = "Send, x";

int main()
{
	std::fstream outFile;
	std::fstream outFile2;
	std::ifstream inFile;
	std::string line;
	std::queue<std::string> inputWords;

	inFile.open(wordsListFilename, std::ios::in);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			inFile >> line;
			inputWords.push(line);
		}
		inFile.close();
	}

	outFile.open(inputFilename, std::ios::in);
	outFile2.open(moddedFilename, std::ios::out);
	if (outFile.is_open() && outFile2.is_open())
	{
		while (!outFile.eof())
		{
			std::getline(outFile, line);
			std::size_t loc = 0;
			std::size_t delimSize = DELIMITER_STR.size();
			while (line.find(DELIMITER_STR, loc) != std::string::npos)
			{
				std::string inputWord = inputWords.front();
				loc = line.find(DELIMITER_STR);
				line.replace((loc+delimSize)-1, 1, inputWord);
				inputWords.pop();
			}
			outFile2 << line << std::endl;
		}
		outFile.close();
		outFile2.close();
	}

	return 0;
}
