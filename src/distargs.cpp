#include<distargs.hpp>
#include<args.hxx> 

struct Registry
{
	std::map<std::string,Command*> mappings;
	std::string arg0;
	std::string helpstring;
	void registerCommand(Command* cmd)
	{
		if(mappings.count(cmd->name))
		{
			throw std::runtime_error(std::string("Error, cannot register command '")+cmd->name+"' more than once!");
		}
		mappings[cmd->name]=cmd;
	}
};

static Registry& getRegistry()
{
	static Registry creg;
	return creg;
}
Command* Command::reglookup(const std::string& name)
{
	Registry& reg=getRegistry();
	auto rcmd=reg.mappings.find(name);
	if(rcmd == reg.mappings.end())
	{
		return nullptr;
	}
	return rcmd->second;
}

Command::Command(const std::string& n):name(n),cmdopts(n,"null")
{
	getRegistry().registerCommand(this);
}

int Command::parseandrun(std::ostream& out,const std::string& helpstring,int argc,char** argv)
{
	getRegistry().arg0=argv[0];
	for(auto name_cmd : getRegistry().mappings)
	{
		cxxopts::Options& lopts=name_cmd.second->cmdopts;
		lopts=name_cmd.second->build_options();
		lopts.add_options(name_cmd.first)
		("help,h",std::string("Print a help message for the '")+name_cmd.first+"' command");
		
	}
	if(argc < 2)
	{
		out << Command::help();
		return 1;
	}
	std::string name=argv[1];
	Command* torun=reglookup(name);
	if(!torun)
	{
		out << "Command '" << name << "' not recognized as a command!" << std::endl;
		out << Command::help();
		return 1;
	}
	argv+=2;
	argc-=2;
	cxxopts::ParseResult pr=torun->cmdopts.parse(argc,argv);
	if(pr.count("help"))
	{
		out << Command::help(name);
	}
	return torun->run(pr);
}
std::string Command::help(const std::string& name)
{
	if(name=="")
	{
		cxxopts::Options mainopts(getRegistry().arg0,getRegistry().helpstring);
		std::string out=mainopts.help({""});
		for(auto name_cmd : getRegistry().mappings)
		{
			cxxopts::Options& lopts=name_cmd.second->cmdopts;
			out+=lopts.help({name_cmd.first});
		}
	}
}


