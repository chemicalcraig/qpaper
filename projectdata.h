/**********************************
 *  Wrapper class for project data
 *  stored in "projects" table in db
 *  for use in treeView_projects
 **********************************/

#ifndef PROJECTDATA_H
#define PROJECTDATA_H

#include "mainwindow.h"

class Projectdata
{
public:
    Projectdata();
    Projectdata(const Projectdata&);

    //Project Id
    int projectId;

    //Is the project a parent or child
    bool isParent;
    bool isChild;

    //Project names and descriptions
    QString name;
    QString description;
    int parentId;
    QString parentName;

    //Number of children
    int nchild;

    //Number of papers associated with project
    int npapers;

    //Functions to set data
    void setName(QString str);
    void setParentId(int id);
    void setDescription(QString str);

    //QStandard item to represent data
    QStandardItem item;

    Projectdata& operator = (const Projectdata& rhs);

};

#endif // PROJECTDATA_H
