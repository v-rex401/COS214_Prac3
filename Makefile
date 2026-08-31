TARGET = eventflow 

# Removed EventComponent.o and EventObserver.o since they are abstract header-only
OBJS = main.o \
CosplayStage.o DemoStation.o EventControl.o EventGroup.o EventNotice.o \
EventUnit.o GamingZone.o MainHall.o \
EventSubject.o \
MedicTeam.o SecurityGuard.o Vendor.o VendorZone.o 

$(TARGET): $(OBJS)
	g++ -std=c++11 -g -o $(TARGET) $(OBJS)

main.o: main.cpp 
	g++ -std=c++11 -g -c main.cpp 

CosplayStage.o: CosplayStage.cpp 
	g++ -std=c++11 -g -c CosplayStage.cpp 

DemoStation.o: DemoStation.cpp 
	g++ -std=c++11 -g -c DemoStation.cpp 

EventControl.o: EventControl.cpp 
	g++ -std=c++11 -g -c EventControl.cpp 

EventGroup.o: EventGroup.cpp
	g++ -std=c++11 -g -c EventGroup.cpp

# Fixed .o extension and fixed -std=c++11 typo
EventNotice.o: EventNotice.cpp
	g++ -std=c++11 -g -c EventNotice.cpp 

EventSubject.o: EventSubject.cpp 
	g++ -std=c++11 -g -c EventSubject.cpp 

EventUnit.o: EventUnit.cpp 
	g++ -std=c++11 -g -c EventUnit.cpp 

GamingZone.o: GamingZone.cpp 
	g++ -std=c++11 -g -c GamingZone.cpp 

MainHall.o: MainHall.cpp
	g++ -std=c++11 -g -c MainHall.cpp 

MedicTeam.o: MedicTeam.cpp 
	g++ -std=c++11 -g -c MedicTeam.cpp 

SecurityGuard.o: SecurityGuard.cpp 
	g++ -std=c++11 -g -c SecurityGuard.cpp 

Vendor.o: Vendor.cpp 
	g++ -std=c++11 -g -c Vendor.cpp 

VendorZone.o: VendorZone.cpp 
	g++ -std=c++11 -g -c VendorZone.cpp

clean: 
	rm -f *.o $(TARGET)

valgrind: eventflow 
	valgrind --leak-check=full ./eventflow
