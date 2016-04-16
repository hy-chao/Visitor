#pragma once
#include<iostream>
#include<list>
using namespace std;
class ConcreteElementA;
class ConcreteElementB;
//visitor类
class Visitor
{
public:
	virtual void VisitConcreteElementA(ConcreteElementA * concreteElementA) = 0;
	virtual void VisitConcreteElementB(ConcreteElementB * concreteElementB) = 0;

};
//具体visitor类
class ConcreteVisitor1 : public Visitor
{
public:
	void VisitConcreteElementA(ConcreteElementA * concreteElementA)
	{
		cout << "concreteElementA被ConcreteVisitor1访问" << endl;
	}
	void VisitConcreteElementB(ConcreteElementB * concreteElementB)
	{
		cout << "concreteElementB被ConcreteVisitor1访问" << endl;
	}
};
class ConcreteVisitor2 : public Visitor
{
public:
	void VisitConcreteElementA(ConcreteElementA * concreteElementA)
	{
		cout << "concreteElementA被ConcreteVisitor2访问" << endl;
	}
	void VisitConcreteElementB(ConcreteElementB * concreteElementB)
	{
		cout << "concreteElementB被ConcreteVisitor2访问" << endl;
	}
};
//Element类
class Element
{
public:
	virtual void Accept(Visitor * visitor) = 0;
};
//具体Element类
class ConcreteElementA : public Element
{
public:
	void Accept(Visitor * visitor)
	{
		visitor->VisitConcreteElementA(this);
	}
	void OperationA()
	{}
};
class ConcreteElementB : public Element
{
public:
	void Accept(Visitor * visitor)
	{
		visitor->VisitConcreteElementB(this);
	}
	void OperationB()
	{}
};
//ObjectStructure类
class ObjectStructure
{
private:
	list<Element *> elements;

public:

	void Attach(Element *element)
	{
		elements.push_back(element);
	}

	void Detach(Element *employee)
	{
		elements.remove(employee);
	}

	void Accept(Visitor *visitor)
	{
		for (list<Element*>::iterator itr = elements.begin(); itr != elements.end(); ++itr)
			(*itr)->Accept(visitor);
	}
};
