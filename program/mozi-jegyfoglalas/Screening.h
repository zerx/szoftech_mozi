#ifndef Screening_H
#define Screening_H

#include "DateTime.h"
#include "Room.h"

class Screening
{
private:
	static int nextId;
	int id;
	string movieName;
	int price;
	DateTime time;
	Room room;
	unsigned int numOfReservations;
	bool isCancelled;

public:
    Screening(const string& movieName, int price, const DateTime& time, const Room& room)
    {
        id=nextId;
        nextId++;
        this->movieName=movieName;
        this->price=price;
        this->time=time;
        this->room=room;
        numOfReservations=0;
        isCancelled=false;
    }

    Screening(){}
    ~Screening(){}
    
	unsigned int checkNumOfFreeSeats()
    {
        return room.getNumOfSeats()-numOfReservations;
    }

	bool operator<(Screening& s)
    {
        if(time < s.time)
            return true;
        else return false;
    }
    
    int getId() const;
    const string& getMovieName() const;
    void setMovieName(const string &value);
    int getPrice() const;
    void setPrice(int value);
    DateTime getTime() const;
    void setTime(const DateTime &value);
    const Room& getRoom() const;
    void setRoom(const Room &value);
    unsigned int getNumOfReservations() const;
    void setNumOfReservations(unsigned int value);
    bool getIsCancelled() const;
    void setIsCancelled(bool value);
};

#endif // Screening_H