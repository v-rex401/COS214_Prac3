# COS214_Prac3

## Team Members

- Jordan Reddy
- Robert Sibanda
- Vashti Pillay

---

## Event Concept

Comic Con is a huge pop culture and gaming festival. This huge festival consists of many different sections tailored to different types of interests. Different sections are dedicated to pop culture, vendors, food vendors, gaming, artists, medical staff, tabletop gaming. All of these areas consist of many different units and people.

---

## Makefile Instructions

- Compile files: `make`
- Run program `make run`
- Check for memory leaks `make valgrind`
- Clean out object files `make clean`

---

## Doxygen Instructions

- Create updated doxygen file Doxyfile run `doxygen Doxyfile`
- Go to `doxygen_docs/html/index.html` to view documentation

---

## Architecure Overview

Our EventFlow program is built in such a way that it can be applied to any given event.

- EventGroup is a Composite, any amount of specific event groupings can be added, as they inherit from this class
- All EventGroup belong to a EventControl Class
- EventGroup can contain leaves or other composite components that have their own leaves or own composites
- EventNotice makes use of an enum to keep the Notice Types
  - EventNotice has a message and NoticeType which is more convenient as we can send
    a message and type in one object s
- Composite and Observer share classes but those shared classes have different roles in each GoF design pattern
- With regards to the Observer, EventGroup acts as both a Subject and an Observer
  - The reason for this is it needs to act in these two different ways for a particular situation
  - It acts as an Observer to the EventControl class
  - It acts as a Subject to the EventUnit classes
