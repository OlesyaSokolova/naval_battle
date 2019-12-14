#pragma once
class Fields
{
public:
	Fields();
	~Fields() = default;
private:
	PointCondition field1_[FIELD_SIZE][FIELD_SIZE];
	PointCondition field2_[FIELD_SIZE][FIELD_SIZE];
};
