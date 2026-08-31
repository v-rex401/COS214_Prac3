TARGET = eventflow 

OBJS = main.o \
CosplayStage.o DemoStation.o EventControl.o EventGroup.o EventNotice.o \
EventUnit.o GamingZone.o MainHall.o \ 
MedicTeam.o SecurityGuard.o Vendor.o VendorZone.o 



$(TARGET) : $(OBJS)
	g++ -std=c++11 -o $(TARGET) $(OBJS)

main.o: main.cpp 
	g++ -std=c++11 -c main.cpp 

CosplayStage.o: CosplayStage.cpp 
	g++ -std=c++11 -c CosplayStage.cpp 

DemoStation.o: DemoStation.cpp 
	g++ -std=c++1 -c DemoStation.cpp 

EventControl.o: EventControl.cpp 
	g++ -std=c++11 -c EventControl.cpp 

EventGroup.o: EventGroup.o 
	g++ -std=c++11 -c EventGroup.o 

EventNotice: EventNotice.cpp
	g++ -std=++11 -c EventNotice.cpp 

EventSubject.o: EventSubject.cpp 
	g++ -std=c++11 -c EventSubject.cpp 

EventUnit.o: EventUnit.cpp 
	g++ -std=c++11 -c EventUnit.cpp 

GamingZone.o: GamingZone.cpp 
	g++ -std=c++11 -c GamingZone.cpp 

MainHall.o: MainHall.cpp
	g++ -std=c++11 -c MainHall.cpp 

MedicTeam.o: MedicTeam.cpp 
	g++ -std=c++11 -c MedicTeam.cpp 

SecurityGuard.o: SecurityGuard.cpp 
	g++ -std=c++11 -c SecurityGuard.cpp 

Vendor.o: Vendor.cpp 
	g++ -std=c++11 -c Vendor.cpp 

VendorZone.o: VendorZone.cpp 
	g++ -std=c++11 -c VendorZone.cpp
	
clean: 
	rm -f *.o $(TARGET)

valgrind: eventflow 
	valgrind --leak-check=full ./eventflow
