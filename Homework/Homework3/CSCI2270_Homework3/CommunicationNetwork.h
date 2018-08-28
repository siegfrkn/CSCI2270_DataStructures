//
//  Assignment4.h
//

#ifndef CommunicationNetwork_h
#define CommunicationNetwork_h

#include <iostream>

struct City{
    std::string cityName;
    std::string message;
    City *next;
    City *previous;

    City(){};

    City(std::string initName, City *initNext, City *initPrevious, std::string initMessage)
    {
        cityName = initName;
        next = initNext;
        previous = initPrevious;
        message = initMessage;
    }
};

class CommunicationNetwork
{
public:
    CommunicationNetwork();
    ~CommunicationNetwork();
    void addCity(std::string, std::string);
    void buildNetwork();
    void transmitMsg(char *);
    void printNetwork();
    void deleteCity(std::string);
    void deleteNetwork();
protected:
private:
    City *head;
    City *tail;
};

#endif // COMMUNICATIONNETWORK_H