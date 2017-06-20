// Material.h: interface for the Material class.
//
//////////////////////////////////////////////////////////////////////

#ifndef MATERIAL_H
#define MATERIAL_H

class Material  
{
friend class Mesh;

private:
	int id;

	int ID();
	void ID(int id);

public:
	Material();
	virtual ~Material();

	void Use();
};

#endif
