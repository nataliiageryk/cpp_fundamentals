#ifndef DMA_H_
#define DMA_H_
#include <iostream>
// Base Class Using DMA
class baseABC
{
private:
	char * label;
	int rating;
public:
	baseABC(const char * l = "null", int r = 0);
	baseABC(const baseABC & rs);
	virtual ~baseABC();
	baseABC & operator=(const baseABC & rs);
	friend std::ostream & operator<<(std::ostream & os, const baseABC & rs);
	virtual void View() const = 0;
};

class baseDMA : public baseABC
{
public:
	baseDMA(const char * l = "null", int r = 0) : baseABC(l,r) {}
	baseDMA(const baseDMA & rs) : baseABC(rs) {}
	virtual ~baseDMA();
	baseDMA & operator=(const baseDMA & rs);
	friend std::ostream & operator<<(std::ostream & os,	const baseDMA & rs);
	virtual void View() const;
};
// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public baseABC
{
private:
	enum { COL_LEN = 40};
	char color[COL_LEN];
public:
	lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	lacksDMA(const char * c, const baseABC & rs);
	friend std::ostream & operator<<(std::ostream & os,
		const lacksDMA & rs);
	virtual void View() const;
};

	// derived class with DMA
class hasDMA :public baseABC
{
private:
	char * style;
public:
	hasDMA(const char * s = "none", const char * l = "null",
		int r = 0);
	hasDMA(const char * s, const baseDMA & rs);
	hasDMA(const hasDMA & hs);
	~hasDMA();
	virtual hasDMA & operator=(const hasDMA & rs);
	friend std::ostream & operator<<(std::ostream & os,
		const hasDMA & rs);
	virtual void View() const;
};
#endif