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