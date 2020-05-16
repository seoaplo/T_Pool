#pragma once
class Command
{
public:
    virtual bool Execute() = 0;
    Command();
    ~Command();

private:

};


class SomeCommand : public Command
{
public:
    virtual bool Execute() override;
    SomeCommand();
    ~SomeCommand();

private:
    //int Some_int; 
};
 bool SomeCommand::Execute()
{
     //Some_Execute!
}

SomeCommand::SomeCommand()
{
}

SomeCommand::~SomeCommand()
{
}