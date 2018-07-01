#ifndef DISTARGS_HPP
#define DISTARGS_HPP

#include<string>
#include<iostream>
#include<memory>

namespace args
{
	class Group;
	class ArgumentParser;
};

class Command
{
private:
	
protected:
	virtual void build_options(args::Group& g)=0;
	virtual int run(const args::Group& parser)=0;
public:	
	std::string name;

	Command(const std::string& n);

	static int parseandrun(std::ostream& out,const std::string&,int argc,char** argv);
	static Command* reglookup(const std::string& name);
	static std::string help(const std::string& name="");
};


#endif
