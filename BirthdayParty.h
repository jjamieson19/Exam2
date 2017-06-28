#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!
// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty
/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:
	std::list<std::string> room; // Data structure for containing the party goers in this dinner party

	BirthdayParty() {}

	friend class PartyFactory;

public:

	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	PartyTicket * add(std::string name) {
		room.push_front(name);
		std::list<std::string>::iterator it = room.begin();;
		BirthdayPartyTicket*newTicket = new BirthdayPartyTicket(this, it);
		return newTicket;
	}

	// List all the persons currently in the party
	
	void list() {
		std::list<std::string>::iterator it = room.begin();
		for (int i = 0; i < room.size(); i++) {
			std::cout << *it << std::endl;
			++it;
		}
	}

	// Remove the person identified by the iterator from the party
	
	void remove(std::list<std::string>::iterator it) {
		room.erase(it);
	}
};

#endif