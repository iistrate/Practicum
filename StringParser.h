#ifndef STRING_PARSER_H
#define STRING_PARSER_H

#include <string>
#include <Python.h>
#include <vector>
#include <string>

#include <iostream>


class StringParser {
private:
	std::string m_scommand;
	std::vector < int > m_icommands;

	//Py Objects
	PyObject *m_POname, *m_POmodule, *m_POfunctionName, *m_POvalues;
	//gil state
	PyGILState_STATE m_gstate;

public:
	StringParser();
	~StringParser();

	//init and close python c api
	void init();
	void close();
	
	//sanitize string before sending it to being drawn and if it is the case 
	//get commands from string
	std::string parseString(std::vector < int > &i_commands, std::string s_command);
};

#endif