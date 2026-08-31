#include "EventNotice.h"

EventNotice::EventNotice()
{
    this->type = NoticeType::BEGIN;
    this->message = "Starting";
}

EventNotice::EventNotice(NoticeType type, std::string msg)
{
    this->type = type;
    this->message = msg;
}

NoticeType EventNotice::getType()
{
    return this->type;
}
std::string EventNotice::getMsg()
{
    return this->message;
}