#include "StringParser.h"

StringParser::StringParser(): m_POfunctionName(NULL), m_POmodule(NULL), m_POname(NULL), m_POvalues(NULL) {
	//start python c apy
	Py_Initialize();
	//init threads
	if (!PyEval_ThreadsInitialized()) {
		PyEval_InitThreads();
	}
}

void StringParser::init() {
	//on init lock gil state
	m_gstate = PyGILState_Ensure();

	//module name
	const char module[] = "Parser";

	//build c string to py object string
	m_POname = Py_BuildValue("s", module);
	//load module into py object
	m_POmodule = PyImport_Import(m_POname);
	Py_DecRef(m_POname);
}

std::string StringParser::parseString(std::vector < int > &f_icommands, std::string s_command) {
	//from string to c string
	const char* cstring = s_command.c_str();
	//if python interpreter is initialized
	if (Py_IsInitialized) {
		//if module is loaded
		if (m_POmodule) {
			//load function
			m_POfunctionName = PyObject_GetAttrString(m_POmodule, "parse");
		}
		//if function exists and is callable
		if (m_POfunctionName && PyCallable_Check(m_POfunctionName)) {
			m_POvalues = PyObject_CallFunctionObjArgs(m_POfunctionName, Py_BuildValue("s", cstring), NULL);
			Py_DecRef(m_POfunctionName);
		}
		if (m_POvalues) {
			//first item is a string
			m_POstring = PyTuple_GetItem(m_POvalues, 0);
			//second item is a list
			m_POlist = PyTuple_GetItem(m_POvalues, 1);
			//empty out commands
			f_icommands.clear();
			int len = PyList_Size(m_POlist);
			for (int i = 0; i < len; i++) {
				//add command
				f_icommands.push_back(PyLong_AsLong(PyList_GetItem(m_POlist, i)));
			}
		}
	}
	//return parsed string
	return PyUnicode_AsUTF8(m_POstring);
}

void StringParser::close() {
//on close kill gill state
PyGILState_Release(m_gstate);
}
StringParser::~StringParser() {
	//close python c api
	Py_Finalize();
}