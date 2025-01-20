#ifndef BAMContigPLUGIN_H
#define BAMContigPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class BAMContigPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "BAMContig";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
