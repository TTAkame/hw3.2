#include<iostream>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

#include "Record.h"
#include "Person.h"
#include "Location.h"
#include "Time.h"

using namespace std;

Json::Value Record::dump2json(){
    Json::Value result{};

    if (pb.name.length() == 0) {
        result["Person"] = pa.dump2json();
      
    }
    else {
        result["Person 1"] = pa.dump2json();
        result["Person 2"] = pb.dump2json();
    }

    if (tb.name.length() == 0 && ta.name.length()!=0) {
        result["Thing"] = ta.dump2json();
    }
    else if (ta.name.length()!=0 && tb.name.length()!=0){
        result["Thing 1"] = ta.dump2json();
        result["Thing 2"] = tb.dump2json();
    }

    result["Location"] = lon.dump2json();
    result["Time"] = tme.dump2json();

    return result;
}

void Record::setPerson(Person ps){
    pa = ps;
}

void Record::setPerson(Person p1, Person p2){
    pa = p1;
    pb = p2;
}

void Record::setThing(Thing tg){
    ta = tg;
}

void Record::setThing(Thing tg,Thing thg){
    ta = tg;
    tb = thg;
}

void Record::setLocation(Location ln){
    lon = ln;
}

void Record::setTime(Time te){
    tme = te;
}

bool Record::JSON2Object(Json::Value x){

	if(x.size()!=0){
	Location l1;
	l1.name=x["Location"]["Description"].toStyledString();



	
//	l1.name=x["Location"];
	//	tme=x.operator["Time"];
		
		if(x.isMember("Person")){

		}

		return 1;
	}

	else{return 0;}

}
