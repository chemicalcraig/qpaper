#include "projectdata.h"

//Normal Constructor
Projectdata::Projectdata()
{
    isParent = true;
    isChild = false;

    nchild = 0;
}

//Copy Constructor
Projectdata::Projectdata(const Projectdata&) {

}

/************************************
 *  Functions
 ************************************/

void Projectdata::setName(QString str) {
    this->name = str;
}

void Projectdata::setDescription(QString str) {
    this->description = str;
}

void Projectdata::setParentId(int id) {
    this->parentId = id;
}

Projectdata& Projectdata::operator =(const Projectdata& other) {
    projectId = other.projectId;
    isParent = other.isParent;
    isChild = other.isChild;
    name = other.name;
    description = other.description;
    parentId = other.parentId;
    nchild = other.nchild;
    npapers = other.npapers;
    //item = other.item.clone();
}
