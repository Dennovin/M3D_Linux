// Header gaurd
#ifndef GCODE_H
#define GCODE_H


// Header files
#include <string>
#include <vector>

using namespace std;


// Class
class Gcode {

	// Public
	public:
	
		/*
		Name: Constructor
		Purpose: Initializes the variable
		*/
		Gcode();
		
		/*
		Name: Copy Constructor
		Purpose: Initializes the variable if copied
		*/
		Gcode(Gcode &value);
		
		/*
		Name: Parse Line
		Purpose: Extracts G-code from the parameter
		*/
		bool parseLine(const char *line);
		bool parseLine(const string &line);
		
		/*
		Name: Get Binary
		Purpose: Returns binary representation of the G-code
		*/
		vector<uint8_t> getBinary() const;
		
		/*
		Name: Get Ascii
		Purpose: Returns Ascii representation of the G-code
		*/
		string getAscii() const;
		
		/*
		Name: Get Data Type
		Purpose: Returns the data type of the G-code
		*/
		uint32_t getDataType() const;
		
		/*
		Name: Has Parameter
		Purpose: Checks if the G-code has a specific identifier, but does not check if it has a value associated with it
		*/
		bool hasParameter(char identifier) const;
		
		/*
		Name: Has Value
		Purpose: Checks if the G-code has a value associated with a specific identifier, so it can't detect flags
		*/
		bool hasValue(char identifier) const;
		
		/*
		Name: Get Value
		Purpose: Retuns the value associated with a specific identifier
		*/
		string getValue(char identifier) const;
		
		/*
		Name: Set Value
		Purpose: Sets the value associated with a specific identifier
		*/
		void setValue(char identifier, const string &value);
		
		/*
		Name: Has String
		Purpose: Returns if the G-code contained a string as a value for a parameter
		*/
		bool hasString() const;
		
		/*
		Name: Get String
		Purpose: Returns the string value associated with a parameter
		*/
		string getString() const;
		
		/*
		Name: Set String
		Purpose: Sets the string value associated with a parameter
		*/
		void setString(const string &value);
		
		/*
		Name: Is Parsed
		Purpose: Returns if any G-code has been successfully parsed yet
		*/
		bool isParsed() const;
		
		/*
		Name: Is Host Command
		Purpose: Returns if the G-code is a host command
		*/
		bool isHostCommand() const;
		
		/*
		Name: Is Empty
		Purpose: Returns if no G-code has attempted to be parsed yet
		*/
		bool isEmpty() const;
		
		/*
		Name: Assignment Operator
		Purpose: Allows using the assignment operator
		*/
		Gcode &operator=(const Gcode &value);
		
		/*
		Name: Output Stream Operator
		Purpose: Allows using the output stream operator
		*/
		friend ostream &operator<<(ostream &output, const Gcode &value);
		
	// Private
	private:
	
		// Original command
		string originalCommand;
	
		// Parameters
		vector<string> parameterValue;
		
		// Data type
		uint32_t dataType;
		
		// Host command
		string hostCommand;
		
		// Parsed
		bool parsed;
		
		// Empty
		bool empty;
};

#endif
