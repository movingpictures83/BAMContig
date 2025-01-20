#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BAMContigPlugin.h"

void BAMContigPlugin::input(std::string file) {
   readParameterFile(file);
}

void BAMContigPlugin::run() {}

void BAMContigPlugin::output(std::string file) {
       	std::string outputfile = file;

	std::string myCommand = "while read -r line; do samtools view -L "+PluginManager::addPrefix(myParameters["alignmentdir"])+"/\"${line}\"_output.bed -h "+PluginManager::addPrefix(myParameters["sortedalign"])+" | samtools view -b - > "+outputfile+"/\"${line}\"_reads.bam; done < "+PluginManager::addPrefix(myParameters["contigs"]);
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<BAMContigPlugin> BAMContigPluginProxy = PluginProxy<BAMContigPlugin>("BAMContig", PluginManager::getInstance());
