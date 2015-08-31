// �������е��󵼺���

#pragma once

#include "DeepVoid Codes/DeepVoid_DataType.h"

// 20150525
struct Point4d
{
	double x, y, z, w; // the point coordinates

	Point4d()
	{
		x=y=z=w=0;
	};

	Point4d(double _x, double _y, double _z, double _w)
	{
		x=_x;
		y=_y;
		z=_z;
		w=_w;
	};

	Point4d & operator = (const Point4d & otherPt)
	{
		if (this != &otherPt)
		{
			x=otherPt.x;
			y=otherPt.y;
			z=otherPt.z;
			w=otherPt.w;
		}

		return *this;
	};

	Point4d(const Point4d & pt)
	{
		*this = pt;
	};
};

namespace derivatives
{

// ���Գ���������fx,fy,cx,cy,s��5���ڲ�����
Matx<double,2,5> der_xy_fxfycxcys(const Matx33d & mR,	// input:	current rotation matrix
								  const Matx31d & mt,	// input:	current translation vector
								  const Matx31d & mX	// input:	current object coordinates
								  );

// ���Գ���������fx,fy,cx,cy,s��5���ڲ�����
Matx<double,2,5> der_xy_fxfycxcys(double u, double v);

// ���Գ���������fx,fy,cx,cy��4���ڲ�����
Matx<double,2,4> der_xy_fxfycxcy(double u, double v);

// ���Գ���������f,cx,cy��3���ڲ�����
Matx<double,2,3> der_xy_fcxcy(double u, double v);

// ���Գ���������f��1���ڲ�����
Matx<double,2,1> der_xy_f(double u, double v);

// ���Գ����Ĺ�һ���������������Գ����������
Matx22d der_uv_xy(double fx, double fy, double s);

// ���Գ������������һ�����������
Matx22d der_xy_uv(double fx, double fy, double s);

// ��һ����������fx,fy,cx,cy,s��5���ڲ�����
Matx<double,2,5> der_uv_fxfycxcys(double x, double y, double fx, double fy, double cx, double cy, double s);

// ��һ�����������Թ�һ�����������
Matx22d der_dudv_uv_weng(double u, double v, double k1, double k2, double k3, double k4, double k5);

// ��һ�����������Թ�һ�����������
Matx22d der_dudv_uv_brown(double u, double v, double k1, double k2, double k3, double k4, double k5);

// ���������Թ�һ������������
Matx22d der_dxdy_dudv(double fx, double fy, double s);

// ����������fx,fy,cx,cy,s��5���ڲ�����
Matx<double,2,5> der_dxdy_fxfycxcys(double du, double dv);

// ����������fx,fy,cx,cy,��4���ڲ�����
Matx<double,2,4> der_dxdy_fxfycxcy(double du, double dv);

// ����������f,cx,cy,��3���ڲ�����
Matx<double,2,3> der_dxdy_fcxcy(double du, double dv);

// ����������f��1���ڲ�����
Matx<double,2,1> der_dxdy_f(double du, double dv);

// ����������fx,fy,cx,cy,s��5���ڲ�����
Matx<double,2,5> der_dxdy_fxfycxcys_weng(double u, double v, double k1, double k2, double k3, double k4, double k5);

// ����������fx,fy,cx,cy��4���ڲ�����
Matx<double,2,4> der_dxdy_fxfycxcy_weng(double u, double v, double k1, double k2, double k3, double k4, double k5);

// ����������fx,fy,cx,cy,s��5���ڲ�����
Matx<double,2,5> der_dxdy_fxfycxcys_brown(double u, double v, double k1, double k2, double k3, double k4, double k5);

// ����������fx,fy,cx,cy,s��4���ڲ�����
Matx<double,2,4> der_dxdy_fxfycxcy_brown(double u, double v, double k1, double k2, double k3, double k4, double k5);

// ���Գ�����������ת���� R ��Ԫ���Լ�ƽ������ t ��Ԫ����
Matx<double,2,12> der_xy_Rt(double fx, double fy, double s, const Matx33d & mR, const Matx31d & mt, const Matx31d & mX);

// ��һ������������ת���� R ��Ԫ���Լ�ƽ������ t ��Ԫ����
Matx<double,2,12> der_uv_Rt(const Matx33d & mR, const Matx31d & mt, const Matx31d & mX);

// ��һ������������ת���� R ��Ԫ���Լ�ƽ������ t ��Ԫ����
Matx<double,2,12> der_uv_Rt(const Matx33d & mR, const Matx31d & mt, double X, double Y, double Z, double W);

// ��һ������������ת���� R ��Ԫ���Լ�ƽ������ t ��Ԫ����
// ���� v1 = r11 X + r12 Y + r13 Z + tx W
//		v2 = r21 X + r22 Y + r23 Z + ty W
//		v3 = r31 X + r32 Y + r33 Z + tz W
Matx<double,2,12> der_uv_Rt(double v1, double v2, double v3, double X, double Y, double Z, double W);

// ��һ������������ת���� R ��Ԫ���Լ��������� c ��
// ���� v1 = r11 (X-Cx) + r12 (Y-Cy) + r13 (Z-Cz)
//		v2 = r21 (X-Cx) + r22 (Y-Cy) + r23 (Z-Cz)
//		v3 = r31 (X-Cx) + r32 (Y-Cy) + r33 (Z-Cz)
// Matx<double,2,12> der_uv_Rc(const Matx33d & R, double u, double v, double v1, double v2, double v3, double X, double Y, double Z, double Cx, double Cy, double Cz);

// ��һ������������ת���� R ��Ԫ���Լ��������� c ��
// ���� v1 = r11 (X-WCx) + r12 (Y-WCy) + r13 (Z-WCz)
//		v2 = r21 (X-WCx) + r22 (Y-WCy) + r23 (Z-WCz)
//		v3 = r31 (X-WCx) + r32 (Y-WCy) + r33 (Z-WCz)
Matx<double,2,12> der_uv_Rc(const Matx33d & R, double u, double v, double v1, double v2, double v3, double X, double Y, double Z, double W, double Cx, double Cy, double Cz);

// ��һ���������Կռ���������XYZW��
// ���� v1 = r11 X + r12 Y + r13 Z + tx W
//		v2 = r21 X + r22 Y + r23 Z + ty W
//		v3 = r31 X + r32 Y + r33 Z + tz W
Matx<double,2,4> der_uv_XYZW(const Matx33d & R, const Matx31d & t, double v1, double v2, double v3);

// ��һ���������Կռ������XYZ��
// ���� v1 = r11 X + r12 Y + r13 Z + tx
//		v2 = r21 X + r22 Y + r23 Z + ty
//		v3 = r31 X + r32 Y + r33 Z + tz
Matx<double,2,3> der_uv_XYZ(const Matx33d & R, double v1, double v2, double v3);

// ��ת����R��Ԫ�ض���ת����w��Ԫ���󵼣�����R=dR*R0��dR=I+[w]�ķ�ʽ��õ�
Matx<double,9,3> der_R_w(const Matx33d & mR);

// ����任����[R|t;0 1]��Ԫ�ض���ת����w��Ԫ���Լ�ƽ��������Ԫ���󵼣�����R=dR*R0��dR=I+[w]�ķ�ʽ��õ�
Matx<double,12,6> der_Rt_wt(const Matx33d & mR);

// ��ת���� R �Լ��������� c ����ת���� w ��Ԫ���Լ��������� c ��Ԫ���󵼣�����R=dR*R0��dR=I+[w]�ķ�ʽ��õ�
Matx<double,12,6> der_Rc_wc(const Matx33d & mR);

// ��һ������������weng's���ϵ����
Matx<double,2,5> der_dudv_ki_weng(double u, double v);

// ��һ������������brown's���ϵ����
Matx<double,2,5> der_dudv_ki_brown(double u, double v);


// ����Լ�����̶���������� /////////////////////////////////////////////////////////////////////////////

// constraint: �̶���ǰͼ��ĳͼ֮��Ļ��߳�Ϊĳֵ: ||Rjck+tj||^2 - d^2 = 0
// ��Լ�����̶Ե�ǰͼ����ת�����Լ�ƽ����������
Matx<double,1,12> der_c_fixedBaseline_Rt(double Xkw,double Ykw, double Zkw,			// ͼ k �Ĺ���������ϵ�е�����
										 double Xkj,double Ykj, double Zkj			// ͼ k �Ĺ����ڵ�ǰͼ��ϵ�е�����
										 );

///////////////////////////////////////////////////////////////////////////////////////////////////////////


Matx<double,2,16> j_f_fxfycxcys_w_t_k1k2k3k4k5(double X, double Y, double Z,	// �ÿ��Ƶ������
											   double x, double y,				// �ÿ��Ƶ��ʵ�ʹ۲��������
											   const Matx33d & mK,				// ��ǰ���ڲ�������
											   const Matx33d & mR,				// ��ǰ����̬����
											   const Matx31d & mt,				// ��ǰ��ƽ����������
											   double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
											   int distType,					// ������ͣ�0 weng's, 1 brown's
											   double & dx, double & dy			// ��ǰ�����µ���ͶӰ�в�
											   );

Matx<double,2,15> j_f_fxfycxcy_w_t_k1k2k3k4k5(double X, double Y, double Z,		// �ÿ��Ƶ������
											  double x, double y,				// �ÿ��Ƶ��ʵ�ʹ۲��������
											  const Matx33d & mK,				// ��ǰ���ڲ�������
											  const Matx33d & mR,				// ��ǰ����̬����
											  const Matx31d & mt,				// ��ǰ��ƽ����������
											  double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
											  int distType,						// ������ͣ�0 weng's, 1 brown's
											  double & dx, double & dy			// ��ǰ�����µ���ͶӰ�в�
											  );

Matx<double,2,14> j_f_fcxcy_w_t_k1k2k3k4k5(double X, double Y, double Z,	// �ÿ��Ƶ������
										   double x, double y,				// �ÿ��Ƶ��ʵ�ʹ۲��������
										   const Matx33d & mK,				// ��ǰ���ڲ�������
										   const Matx33d & mR,				// ��ǰ����̬����
										   const Matx31d & mt,				// ��ǰ��ƽ����������
										   double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
										   int distType,					// ������ͣ�0 weng's, 1 brown's
										   double & dx, double & dy			// ��ǰ�����µ���ͶӰ�в�
										   );

Matx<double,2,12> j_f_f_w_t_k1k2k3k4k5(double X, double Y, double Z,	// �ÿ��Ƶ������
									   double x, double y,				// �ÿ��Ƶ��ʵ�ʹ۲��������
									   const Matx33d & mK,				// ��ǰ���ڲ�������
									   const Matx33d & mR,				// ��ǰ����̬����
									   const Matx31d & mt,				// ��ǰ��ƽ����������
									   double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
									   int distType,					// ������ͣ�0 weng's, 1 brown's
									   double & dx, double & dy			// ��ǰ�����µ���ͶӰ�в�
									   );

Matx<double,2,11> j_f_fxfycxcy_w_t_k1(double X, double Y, double Z,		// �ÿ��Ƶ������
									  double x, double y,				// �ÿ��Ƶ��ʵ�ʹ۲��������
									  const Matx33d & mK,				// ��ǰ���ڲ�������
									  const Matx33d & mR,				// ��ǰ����̬����
									  const Matx31d & mt,				// ��ǰ��ƽ����������
									  double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
									  int distType,						// ������ͣ�0 weng's, 1 brown's
									  double & dx, double & dy			// ��ǰ�����µ���ͶӰ�в�
									  );

Matx<double,2,10> j_f_fcxcy_w_t_k1(double X, double Y, double Z,	// �ÿ��Ƶ������
								   double x, double y,				// �ÿ��Ƶ��ʵ�ʹ۲��������
								   const Matx33d & mK,				// ��ǰ���ڲ�������
								   const Matx33d & mR,				// ��ǰ����̬����
								   const Matx31d & mt,				// ��ǰ��ƽ����������
								   double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
								   int distType,					// ������ͣ�0 weng's, 1 brown's
								   double & dx, double & dy			// ��ǰ�����µ���ͶӰ�в�
								   );

Matx<double,2,12> j_f_fxfycxcy_w_t_k1k2(double X, double Y, double Z,	// �ÿ��Ƶ������
										double x, double y,				// �ÿ��Ƶ��ʵ�ʹ۲��������
										const Matx33d & mK,				// ��ǰ���ڲ�������
										const Matx33d & mR,				// ��ǰ����̬����
										const Matx31d & mt,				// ��ǰ��ƽ����������
										double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
										int distType,					// ������ͣ�0 weng's, 1 brown's
										double & dx, double & dy		// ��ǰ�����µ���ͶӰ�в�
										);

Matx<double,2,11> j_f_fcxcy_w_t_k1k2(double X, double Y, double Z,	// �ÿ��Ƶ������
								     double x, double y,			// �ÿ��Ƶ��ʵ�ʹ۲��������
								     const Matx33d & mK,			// ��ǰ���ڲ�������
								     const Matx33d & mR,			// ��ǰ����̬����
								     const Matx31d & mt,			// ��ǰ��ƽ����������
								     double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
								     int distType,					// ������ͣ�0 weng's, 1 brown's
								     double & dx, double & dy		// ��ǰ�����µ���ͶӰ�в�
								     );

// Bundle adjustment ��ص��󵼺����ۺ��� ////////////////////////////////
void j_f_w_t_XYZW(double X, double Y, double Z,	double W,	// �ÿ��Ƶ���������
				  double x, double y,						// �ÿ��Ƶ��ʵ�ʹ۲��������
				  const Matx33d & mK,						// ��ǰ���ڲ�������
				  const Matx33d & mR,						// ��ǰ����̬����
				  const Matx31d & mt,						// ��ǰ��ƽ����������
				  double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
				  int distType,								// ������ͣ�0 weng's, 1 brown's
				  Matx<double,2,6> & A,						// ��ͶӰ�����������������ĵ�
				  Matx<double,2,4> & B,						// ��ͶӰ�������Կռ������XYZW��ĵ�
				  double & dx, double & dy					// ��ǰ�����µ���ͶӰ�в�
				  );

void j_f_w_t_XYZ(double X, double Y, double Z,	double W,	// �ÿ��Ƶ���������
				 double x, double y,						// �ÿ��Ƶ��ʵ�ʹ۲��������
				 const Matx33d & mK,						// ��ǰ���ڲ�������
				 const Matx33d & mR,						// ��ǰ����̬����
				 const Matx31d & mt,						// ��ǰ��ƽ����������
				 double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
				 int distType,								// ������ͣ�0 weng's, 1 brown's
				 Matx<double,2,6> & A,						// ��ͶӰ�����������������ĵ�
				 Matx<double,2,3> & B,						// ��ͶӰ�������Կռ������ XYZ ��ĵ�
				 double & dx, double & dy					// ��ǰ�����µ���ͶӰ�в�
				 );

void j_f_w_c_XYZW(double X, double Y, double Z, double W,	// �ÿ��Ƶ���������
				  double x, double y,						// �ÿ��Ƶ��ʵ�ʹ۲��������
				  const Matx33d & mK,						// ��ǰ���ڲ�������
				  const Matx33d & mR,						// ��ǰ����̬����
				  const Matx31d & mc,						// ��ǰ�Ĺ����������
				  double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
				  int distType,								// ������ͣ�0 weng's, 1 brown's
				  Matx<double,2,6> & A,						// ��ͶӰ�����������������ĵ�
				  Matx<double,2,4> & B,						// ��ͶӰ�������Կռ������ XYZW ��ĵ�
				  double & dx, double & dy					// ��ǰ�����µ���ͶӰ�в�
				  );

void j_f_w_c_XYZ(double X, double Y, double Z, double W,	// �ÿ��Ƶ��������꣬�˴� W ӦΪ 1
				 double x, double y,						// �ÿ��Ƶ��ʵ�ʹ۲��������
				 const Matx33d & mK,						// ��ǰ���ڲ�������
				 const Matx33d & mR,						// ��ǰ����̬����
				 const Matx31d & mc,						// ��ǰ�Ĺ����������
				 double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
				 int distType,								// ������ͣ�0 weng's, 1 brown's
				 Matx<double,2,6> & A,						// ��ͶӰ�����������������ĵ�
				 Matx<double,2,3> & B,						// ��ͶӰ�������Կռ������ XYZ ��ĵ�
				 double & dx, double & dy					// ��ǰ�����µ���ͶӰ�в�
				 );

void j_f_f_w_t_XYZW(double X, double Y, double Z,	double W,	// �ÿ��Ƶ���������
				    double x, double y,							// �ÿ��Ƶ��ʵ�ʹ۲��������
					const Matx33d & mK,							// ��ǰ���ڲ�������
					const Matx33d & mR,							// ��ǰ����̬����
					const Matx31d & mt,							// ��ǰ��ƽ����������
					double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
					int distType,								// ������ͣ�0 weng's, 1 brown's
					Matx<double,2,6> & A,						// ��ͶӰ�����������������ĵ�
					Matx<double,2,4> & B,						// ��ͶӰ�������Կռ������XYZW��ĵ�
					Matx<double,2,1> & C,						// ��ͶӰ��������һ����Ч���� f ��
					double & dx, double & dy					// ��ǰ�����µ���ͶӰ�в�
					);

void j_f_f_w_c_XYZ(double X, double Y, double Z,	double W,	// �ÿ��Ƶ���������
				   double x, double y,							// �ÿ��Ƶ��ʵ�ʹ۲��������
				   const Matx33d & mK,							// ��ǰ���ڲ�������
				   const Matx33d & mR,							// ��ǰ����̬����
				   const Matx31d & mc,							// ��ǰ�Ĺ����������
				   double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
				   int distType,								// ������ͣ�0 weng's, 1 brown's
				   Matx<double,2,6> & A,						// ��ͶӰ�����������������ĵ�
				   Matx<double,2,3> & B,						// ��ͶӰ�������Կռ������XYZ��ĵ�
				   Matx<double,2,1> & C,						// ��ͶӰ��������һ����Ч���� f ��
				   double & dx, double & dy						// ��ǰ�����µ���ͶӰ�в�
				   );

// ������ȵ� BA �����У�һ���ɵ���������� xij �������ͼ������� w t ��
// ��Ҫ����ο�ͼ������� w0 t0 ��
// ���Ҫ�Ը��������ο�ͼ�е���� d0 ������
void j_f_w_t_w0_t0_d0(double d0,				// ���룺��ǰ������������ο�ͼ�����ȹ���
					  double x, double y,		// ���룺������ڵ�ǰ����ͼ���еĹ۲��������
					  const Matx33d & mK,		// ���룺��ǰ����ͼ����ڲ�������
					  const Matx33d & mR,		// ���룺��ǰ����ͼ�����̬����
					  const Matx31d & mt,		// ���룺��ǰ����ͼ���ƽ����������
					  double k1,double k2,double k3, double k4, double k5,	// ���룺��ǰ����ͼ������ϵ������
					  int distType,				// ���룺��ǰ����ͼ���������ͣ�0 weng's, 1 brown's
					  const Matx31d & nx0,		// ���룺���������ο�ͼ��ϵ�еĹ�һ��������꣬��������������߷���
					  const Matx33d & mR0,		// ���룺��ǰ�ο�ͼ�����̬����
					  const Matx31d & mt0,		// ���룺��ǰ�ο�ͼ���ƽ����������
					  Matx<double,2,6> & A,		// �������ͶӰ�������Գ���ͼ�������ĵ�
					  Matx<double,2,1> & B,		// �������ͶӰ���������������ĵ�
					  Matx<double,2,6> & A0,	// �������ͶӰ�������Բο�ͼ�������ĵ�
					  double & dx, double & dy	// �������ǰ�����µ���ͶӰ�в�
					  );


// void j_f_w_t_XYZW(const vector<Point4d> & XYZWs,			// ���룺n���ռ��XYZW����
// 				  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
// 				  const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
// 				  const vector<Matx31d> & ts,				// ���룺m��ͼ��ƽ������
// 				  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
// 				  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
// 				  const vector<Point2d> & xys,				// ���룺����ͼ���ϵ�������꣬������Ϊ m*n ��
// 				  const vector<int> & j_fixed,				// ���룺��Щͼ��Ĳ����ǹ̶��ģ����ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
// 				  const vector<int> & i_fixed,				// ���룺��Щ�ռ�������ǹ̶��ģ������ i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
// 				  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
// 				  vector<Matx<double,2,6>> & A,				// ��������е�Aij���������ų�һ������
// 				  vector<Matx<double,2,4>> & B,				// ��������е�Bij���������ų�һ������
// 				  vector<Matx21d> & e						// ��������е� eij = xij - Q(aj,bi) ���������ų�һ������
// 				  );

void j_f_w_t_XYZW(const vector<Point4d> & XYZWs,			// ���룺n���ռ��XYZW����
				  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
				  const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
				  const vector<Matx31d> & ts,				// ���룺m��ͼ��ƽ������
				  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
				  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
				  const vector<Point2d> & xys,				// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
				  const vector<Matx22d> & covInvs,			// ���룺l�������������Э�������������
				  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
				  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
				  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
				  vector<Matx<double,6,6>> & U,				// �����m��Uj���󣬽���ͼ������й�
				  vector<Matx<double,4,4>> & V,				// �����n��Vi���󣬽����ռ�������й�
				  vector<Matx<double,6,4>> & W,				// �����l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
				  vector<Matx<double,6,1>> & ea,			// �����m��eaj�в�����������ͼ������й�
				  vector<Matx<double,4,1>> & eb,			// �����n��ebi�в������������ռ�������й�
				  Mat & f,									// �����2*l�����в�������ʵҲ�������۵�Ŀ�꺯��ֵ
				  Mat & g,									// �����6*m+4*nά�Ĳ����ݶ�
				  vector<double> & vds						// �����l��������ͶӰ�в���
				  );

void j_f_w_t_XYZ(const vector<Point3d> & XYZs,			// ���룺n���ռ��XYZ����
				 const vector<Matx33d> & Ks,			// ���룺m��ͼ���ڲ�������
				 const vector<Matx33d> & Rs,			// ���룺m��ͼ����ת����
				 const vector<Matx31d> & ts,			// ���룺m��ͼ��ƽ������
				 const vector<Matx<double,5,1>> & dists,// ���룺m��ͼ�����ϵ��
				 const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
				 const vector<Point2d> & xys,			// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
				 const vector<Matx22d> & covInvs,		// ���룺l�������������Э�������������
				 const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
				 const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
				 const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
				 vector<Matx<double,6,6>> & U,			// �����m��Uj���󣬽���ͼ������й�
				 vector<Matx<double,3,3>> & V,			// �����n��Vi���󣬽����ռ�������й�
				 vector<Matx<double,6,3>> & W,			// �����l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
				 vector<Matx<double,6,1>> & ea,			// �����m��eaj�в�����������ͼ������й�
				 vector<Matx<double,3,1>> & eb,			// �����n��ebi�в������������ռ�������й�
				 Mat & f,								// �����2*l�����в�������ʵҲ�������۵�Ŀ�꺯��ֵ
				 Mat & g,								// �����6*m+3*nά�Ĳ����ݶ�
				 vector<double> & vds					// �����l��������ͶӰ�в���
				 );

void j_f_w_c_XYZW(const vector<Point4d> & XYZWs,			// ���룺n���ռ��XYZW����
				  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
				  const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
				  const vector<Matx31d> & cs,				// ���룺m��ͼ���������
				  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
				  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
				  const vector<Point2d> & xys,				// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
				  const vector<Matx22d> & covInvs,			// ���룺l�������������Э�������������
				  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
				  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
				  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
				  vector<Matx<double,6,6>> & U,				// �����m��Uj���󣬽���ͼ������й�
				  vector<Matx<double,4,4>> & V,				// �����n��Vi���󣬽����ռ�������й�
				  vector<Matx<double,6,4>> & W,				// �����l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
				  vector<Matx<double,6,1>> & ea,			// �����m��eaj�в�����������ͼ������й�
				  vector<Matx<double,4,1>> & eb,			// �����n��ebi�в������������ռ�������й�
				  Mat & f,									// �����2*l�����в�������ʵҲ�������۵�Ŀ�꺯��ֵ
				  Mat & g,									// �����6*m+4*nά�Ĳ����ݶ�
				  vector<double> & vds						// �����l��������ͶӰ�в���
				  );

void j_f_w_c_XYZ(const vector<Point3d> & XYZs,			// ���룺n���ռ��XYZ����
				 const vector<Matx33d> & Ks,			// ���룺m��ͼ���ڲ�������
				 const vector<Matx33d> & Rs,			// ���룺m��ͼ����ת����
				 const vector<Matx31d> & cs,			// ���룺m��ͼ���������
				 const vector<Matx<double,5,1>> & dists,// ���룺m��ͼ�����ϵ��
				 const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
				 const vector<Point2d> & xys,			// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
				 const vector<Matx22d> & covInvs,		// ���룺l�������������Э�������������
				 const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
				 const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
				 const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
				 vector<Matx<double,6,6>> & U,			// �����m��Uj���󣬽���ͼ������й�
				 vector<Matx<double,3,3>> & V,			// �����n��Vi���󣬽����ռ�������й�
				 vector<Matx<double,6,3>> & W,			// �����l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
				 vector<Matx<double,6,1>> & ea,			// �����m��eaj�в�����������ͼ������й�
				 vector<Matx<double,3,1>> & eb,			// �����n��ebi�в������������ռ�������й�
				 Mat & f,								// �����2*l�����в�������ʵҲ�������۵�Ŀ�꺯��ֵ
				 Mat & g,								// �����6*m+3*nά�Ĳ����ݶ�
				 vector<double> & vds					// �����l��������ͶӰ�в���
				 );

void j_f_f_w_t_XYZW(const vector<Point4d> & XYZWs,			// ���룺n���ռ��XYZW����
					const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
				    const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
				    const vector<Matx31d> & ts,				// ���룺m��ͼ��ƽ������
				    const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
				    const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
				    const vector<Point2d> & xys,			// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
				    const vector<Matx22d> & covInvs,		// ���룺l�������������Э�������������
				    const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
				    const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
				    const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
				    vector<Matx<double,6,6>> & U,			// �����m��Uj���󣬽���ͼ������й�
				    vector<Matx<double,4,4>> & V,			// �����n��Vi���󣬽����ռ�������й�
				    vector<Matx<double,6,4>> & W,			// �����l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
					Matx<double,1,1> & Q,					// �����Ψһһ��Q����ֻ���������й�
					vector<Matx<double,1,6>> & G,			// �����m��Gj����ͬʱ�Ͷ��м�����ͼ������й�
					vector<Matx<double,1,4>> & H,			// �����n��Hi����ͬʱ�͹���ͼ������Լ�����й�
				    vector<Matx<double,6,1>> & ea,			// �����m��eaj�в�����������ͼ������й�
				    vector<Matx<double,4,1>> & eb,			// �����n��ebi�в������������ռ�������й�
					Matx<double,1,1> & ec,					// �����Ψһһ��ec�в���������������ͼ������й�
				    Mat & f,								// �����2*l�����в�������ʵҲ�������۵�Ŀ�꺯��ֵ
				    Mat & g,								// �����1+6*m+4*nά�Ĳ����ݶ�
				    vector<double> & vds					// �����l��������ͶӰ�в���
				    );

void j_f_f_w_c_XYZ(const vector<Point3d> & XYZs,			// ���룺n���ռ��XYZ����
				   const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
				   const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
				   const vector<Matx31d> & cs,				// ���룺m��ͼ���������
				   const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
				   const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
				   const vector<Point2d> & xys,				// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
				   const vector<Matx22d> & covInvs,			// ���룺l�������������Э�������������
				   const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
				   const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
				   const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
				   vector<Matx<double,6,6>> & U,			// �����m��Uj���󣬽���ͼ������й�
				   vector<Matx<double,3,3>> & V,			// �����n��Vi���󣬽����ռ�������й�
				   vector<Matx<double,6,3>> & W,			// �����l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
				   Matx<double,1,1> & Q,					// �����Ψһһ��Q����ֻ���������й�
				   vector<Matx<double,1,6>> & G,			// �����m��Gj����ͬʱ�Ͷ��м�����ͼ������й�
				   vector<Matx<double,1,3>> & H,			// �����n��Hi����ͬʱ�͹���ͼ������Լ�����й�
				   vector<Matx<double,6,1>> & ea,			// �����m��eaj�в�����������ͼ������й�
				   vector<Matx<double,3,1>> & eb,			// �����n��ebi�в������������ռ�������й�
				   Matx<double,1,1> & ec,					// �����Ψһһ��ec�в���������������ͼ������й�
				   Mat & f,									// �����2*l�����в�������ʵҲ�������۵�Ŀ�꺯��ֵ
				   Mat & g,									// �����1+6*m+3*nά�Ĳ����ݶ�
				   vector<double> & vds						// �����l��������ͶӰ�в���
				   );

void j_f_f_w_t_XYZW_c_fixedBaseline(const vector<Point4d> & XYZWs,			// ���룺n���ռ��XYZW����
									const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
									const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
									const vector<Matx31d> & ts,				// ���룺m��ͼ��ƽ������
									const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
									const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
									const vector<Point2d> & xys,			// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
									const vector<Matx22d> & covInvs,		// ���룺l�������������Э�������������
									const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
									const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
									const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
									int k_fixedBaseLine,					// ���룺������ͼ��֮��Ļ��߹̶�������k �ǲ�������һ��
									int j_fixedBaseLine,					// ���룺������ͼ��֮��Ļ��߹̶�������j �ǵ�����һ��
									double d_fixedBaseLine,					// ���룺����ͼ��֮��Ĺ̶����߳���
									vector<Matx<double,6,6>> & U,			// �����m��Uj���󣬽���ͼ������й�
									vector<Matx<double,4,4>> & V,			// �����n��Vi���󣬽����ռ�������й�
									vector<Matx<double,6,4>> & W,			// �����l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
									Matx<double,1,1> & Q,					// �����Ψһһ��Q����ֻ���������й�
									vector<Matx<double,1,6>> & G,			// �����m��Gj����ͬʱ�Ͷ��м�����ͼ������й�
									vector<Matx<double,1,4>> & H,			// �����n��Hi����ͬʱ�͹���ͼ������Լ�����й�
									vector<Matx<double,6,1>> & ea,			// �����m��eaj�в�����������ͼ������й�
									vector<Matx<double,4,1>> & eb,			// �����n��ebi�в������������ռ�������й�
									Matx<double,1,1> & ec,					// �����Ψһһ��ec�в���������������ͼ������й�
									Mat & f,								// �����2*l�����в�������ʵҲ�������۵�Ŀ�꺯��ֵ
									Mat & g,								// �����1+6*m+4*nά�Ĳ����ݶ�
									vector<double> & vds,					// �����l��������ͶӰ�в���
									Matx<double,1,6> & Daj,					// �����Լ�����̶Թ̶����ߵ� j ���������
									double & h								// �����Լ�����̵�ǰ��ֵ
									);

// ������ȵ� BA �����У����пɵ���������� xij �������ͼ������� w t ��
// ��Ҫ����ο�ͼ������� w0 t0 ��
// ���Ҫ�Ը��������ο�ͼ�е���� d0 ������
void j_f_w_t_w0_t0_d0(const vector<double> & ds,				// ���룺n���ռ����������ֵ
					  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
					  const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
					  const vector<Matx31d> & ts,				// ���룺m��ͼ��ƽ������
					  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
					  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
					  const vector<Point2d> & xys,				// ���룺l������ͼ���ϵĿɵ���������꣬������Ϊ m*n ��
					  const vector<Matx22d> & covInvs,			// ���룺l�����пɵ����������Э�������������
					  const vector<Matx31d> & nxys,				// ���룺n��������������ο�ͼ��ϵ�еĹ۲����߷���Ҳ����һ���������
					  const vector<int> & ri_j,					// ���룺n���������Ĳο�ͼ���������һ�� i ����Ӧһ�� j
					  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
					  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ������ǹ̶��ģ�i_fixed[i]=1��������� i ��ȹ̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
					  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
					  vector<Matx<double,6,6>> & U,				// ������ܹ�(m+1)m/2��Ujk���󣬽���ͼ������й�
					  vector<double> & V,						// �����n��Vi���󣬽�������й�
					  vector<Matx<double,6,1>> & W,				// �����l��Wij����ͬʱ����ȼ���۲�ͼ���й�
					  vector<Matx<double,6,1>> & ea,			// �����m��eaj�в�����������ͼ������й�
					  vector<double> & eb,						// �����n��ebi�в������������ռ�������й�
					  Mat & f,									// �����2*l�����в�������ʵҲ�������۵�Ŀ�꺯��ֵ
					  Mat & g,									// �����6*m+nά�Ĳ����ݶ�
					  vector<double> & vds						// �����l��������ͶӰ�в���
					  );

// ������ȵ� BA �����У������������ xij �������ɵ����ķǲο�����Լ����ɵ����Ĳο���㣩�������ͼ������� w t ��
// ��Ҫ����ο�ͼ������� w0 t0 ��
// ���Ҫ�Ը��������ο�ͼ�е���� d0 ������
void j_f_w_t_w0_t0_d0_new(const vector<double> & ds,			// ���룺n���ռ����������ֵ
					  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
					  const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
					  const vector<Matx31d> & ts,				// ���룺m��ͼ��ƽ������
					  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
					  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
					  const vector<Point2d> & xys,				// ���룺l���۲�������꣬���Ϊ m*n ��
					  const vector<Matx22d> & covInvs,			// ���룺l���۲��������Э�������������
					  const vector<Matx31d> & nxys,				// ���룺n��������������ο�ͼ��ϵ�еĹ۲����߷���Ҳ����һ���������
					  const vector<int> & ri_j,					// ���룺n���������Ĳο�ͼ���������һ�� i ����Ӧһ�� j
					  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
					  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ������ǹ̶��ģ�i_fixed[i]=1��������� i ��ȹ̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
					  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
					  vector<Matx<double,6,6>> & U,				// ������ܹ�(m+1)m/2��Ujk���󣬽���ͼ������й�
					  vector<double> & V,						// �����n��Vi���󣬽�������й�
					  vector<Matx<double,6,1>> & W,				// �����l��Wij����ͬʱ����ȼ���۲�ͼ���й�
					  vector<Matx<double,6,1>> & ea,			// �����m��eaj�в�����������ͼ������й�
					  vector<double> & eb,						// �����n��ebi�в������������ռ�������й�
					  Mat & f,									// �����2*l�����в�������ʵҲ�������۵�Ŀ�꺯��ֵ
					  Mat & g,									// �����6*m+nά�Ĳ����ݶ�
					  vector<double> & vds						// �����l��������ͶӰ�в���
					  );

// ������ȵ� BA �����У������������ xij �������ɵ����ķǲο�����Լ����ɵ����Ĳο���㣩�������ͼ������� w t ��
// ��Ҫ����ο�ͼ������� w0 t0 ��
// ���Ҫ�Ը��������ο�ͼ�е���� d0 ������
void j_f_w_t_w0_t0_d0_new2(const vector<double> & ds,			// ���룺n���ռ����������ֵ
					  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
					  const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
					  const vector<Matx31d> & ts,				// ���룺m��ͼ��ƽ������
					  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
					  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
					  const vector<Point2d> & xys,				// ���룺l���۲�������꣬���Ϊ m*n ��
					  const vector<Matx22d> & covInvs,			// ���룺l���۲��������Э�������������
					  const vector<Matx31d> & nxys,				// ���룺n��������������ο�ͼ��ϵ�еĹ۲����߷���Ҳ����һ���������
					  const vector<int> & ri_j,					// ���룺n���������Ĳο�ͼ���������һ�� i ����Ӧһ�� j
					  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
					  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ������ǹ̶��ģ�i_fixed[i]=1��������� i ��ȹ̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
					  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
					  vector<Matx<double,6,6>> & U,				// ������ܹ�(m+1)m/2��Ujk���󣬽���ͼ������й�
					  vector<Matx<double,1,1>> & V,				// �����n��Vi���󣬽�������й�
					  vector<Matx<double,6,1>> & W,				// �����l��Wij����ͬʱ����ȼ���۲�ͼ���й�
					  vector<Matx<double,6,1>> & ea,			// �����m��eaj�в�����������ͼ������й�
					  vector<Matx<double,1,1>> & eb,			// �����n��ebi�в������������ռ�������й�
					  Mat & f,									// �����2*l�����в�������ʵҲ�������۵�Ŀ�꺯��ֵ
					  Mat & g,									// �����6*m+nά�Ĳ����ݶ�
					  vector<double> & vds						// �����l��������ͶӰ�в���
					  );

// ��� 0 �������������6 ��������в����� 4 �������в����� Sparse Bundle Adjustment ������������淽��
void solveSBA_0_6_4(double u,								// ���룺����ϵ��
					const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
					const vector<Matx<double,6,6>> & U,		// ���룺m��Uj���󣬽���ͼ������й�
					const vector<Matx<double,4,4>> & V,		// ���룺n��Vi���󣬽����ռ�������й�
					const vector<Matx<double,6,4>> & W,		// ���룺l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
					const vector<Matx<double,6,1>> & ea,	// ���룺m��eaj�в�����������ͼ������й�
					const vector<Matx<double,4,1>> & eb,	// ���룺n��ebi�в������������ռ�������й�
					vector<Matx<double,6,1>> & da,			// �����m��ͼ������ĸ�����
					vector<Matx<double,4,1>> & db,			// �����n���ռ������ĸ�����
					Mat & h									// �����6*m+4*nά�Ĳ���������
					);

void solveSBA_0_6_3(double u,								// ���룺����ϵ��
				    const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
				    const vector<Matx<double,6,6>> & U,		// ���룺m��Uj���󣬽���ͼ������й�
				    const vector<Matx<double,3,3>> & V,		// ���룺n��Vi���󣬽����ռ�������й�
				    const vector<Matx<double,6,3>> & W,		// ���룺l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
				    const vector<Matx<double,6,1>> & ea,	// ���룺m��eaj�в�����������ͼ������й�
				    const vector<Matx<double,3,1>> & eb,	// ���룺n��ebi�в������������ռ�������й�
				    vector<Matx<double,6,1>> & da,			// �����m��ͼ������ĸ�����
				    vector<Matx<double,3,1>> & db,			// �����n���ռ������ĸ�����
				    Mat & h									// �����6*m+3*nά�Ĳ���������
				    );

void solveSBA_1_6_4(double u,								// ���룺����ϵ��
					const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
					const vector<Matx<double,6,6>> & U,		// ���룺m��Uj���󣬽���ͼ������й�
					const vector<Matx<double,4,4>> & V,		// ���룺n��Vi���󣬽����ռ�������й�
					const vector<Matx<double,6,4>> & W,		// ���룺l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
					const Matx<double,1,1> & Q,				// ���룺Ψһһ��Q����ֻ���������й�
					const vector<Matx<double,1,6>> & G,		// ���룺m��Gj����ͬʱ�Ͷ��м�����ͼ������й�
					const vector<Matx<double,1,4>> & H,		// ���룺n��Hi����ͬʱ�͹���ͼ������Լ�����й�
					const vector<Matx<double,6,1>> & ea,	// ���룺m��eaj�в�����������ͼ������й�
					const vector<Matx<double,4,1>> & eb,	// ���룺n��ebi�в������������ռ�������й�
					const Matx<double,1,1> & ec,			// ���룺Ψһһ��ec�в���������������ͼ������й�
					vector<Matx<double,6,1>> & da,			// �����m��ͼ������ĸ�����
					vector<Matx<double,4,1>> & db,			// �����n���ռ������ĸ�����
					Matx<double,1,1> & dc,					// ���������ͼ������ĸ�����
					Mat & h									// �����1+6*m+4*nά�Ĳ���������
					);

void solveSBA_1_6_4_Daj(double u,								// ���룺����ϵ��
						const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
						const vector<Matx<double,6,6>> & U,		// ���룺m��Uj���󣬽���ͼ������й�
						const vector<Matx<double,4,4>> & V,		// ���룺n��Vi���󣬽����ռ�������й�
						const vector<Matx<double,6,4>> & W,		// ���룺l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
						const Matx<double,1,1> & Q,				// ���룺Ψһһ��Q����ֻ���������й�
						const vector<Matx<double,1,6>> & G,		// ���룺m��Gj����ͬʱ�Ͷ��м�����ͼ������й�
						const vector<Matx<double,1,4>> & H,		// ���룺n��Hi����ͬʱ�͹���ͼ������Լ�����й�
						const vector<Matx<double,6,1>> & ea,	// ���룺m��eaj�в�����������ͼ������й�
						const vector<Matx<double,4,1>> & eb,	// ���룺n��ebi�в������������ռ�������й�
						const Matx<double,1,1> & ec,			// ���룺Ψһһ��ec�в���������������ͼ������й�
						int j_constrained,						// ���룺��Լ����ͼ�������
						const vector<Matx<double,1,6>> & Daj,	// ���룺ÿ��Լ�����̶Ե� j ��ͼ����в����ĵ���
						const vector<double> & hs,				// ���룺ÿ��Լ�������ڵ�ǰ�����µ�ֵ
						vector<Matx<double,6,1>> & da,			// �����m��ͼ������ĸ�����
						vector<Matx<double,4,1>> & db,			// �����n���ռ������ĸ�����
						Matx<double,1,1> & dc,					// ���������ͼ������ĸ�����
						Mat & h,								// �����1+6*m+4*nά�Ĳ���������
						double & val							// �����0.5*dx'C'lamda
						);

// 20150721,�������һά���������ʾ
void solveSBA_0_6_1(double u,								// ���룺����ϵ��
				    const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ������
				    const vector<Matx<double,6,6>> & U,		// ���룺�ܹ�(m+1)m/2�� Ujk ���󣬽���ͼ������й�
				    const vector<Matx<double,1,1>> & V,		// ���룺n��Vi���󣬽����ռ������й�
				    const vector<Matx<double,6,1>> & W,		// ���룺l��Wij����ͬʱ���ռ����ȼ���۲�ͼ���й�
				    const vector<Matx<double,6,1>> & ea,	// ���룺m��eaj�в�����������ͼ������й�
				    const vector<Matx<double,1,1>> & eb,	// ���룺n��ebi�в������������ռ������й�
				    vector<Matx<double,6,1>> & da,			// �����m��ͼ������ĸ�����
				    vector<Matx<double,1,1>> & db,			// �����n���ռ����ȵĸ�����
				    Mat & h									// �����6*m+nά�Ĳ���������
				    );

// void covarianceSBA_0_6_4(const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
// 						 const vector<Matx<double,6,6>> & U,	// ���룺m��Uj���󣬽���ͼ������й�
// 						 const vector<Matx<double,4,4>> & V,	// ���룺n��Vi���󣬽����ռ�������й�
// 						 const vector<Matx<double,6,4>> & W		// ���룺l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
// 						 );

void covarianceSBA_0_6_3(const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
						 const vector<Matx<double,6,6>> & U,	// ���룺m��Uj���󣬽���ͼ������й�
						 const vector<Matx<double,3,3>> & V,	// ���룺n��Vi���󣬽����ռ�������й�
						 const vector<Matx<double,6,3>> & W,	// ���룺l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
						 vector<Matx<double,6,6>> & cov_a,		// �����m��ͼ����в�����Э�������
						 vector<Matx<double,3,3>> & cov_b		// �����n���ռ��������Э�������
						 );

void covarianceSBA_1_6_3(const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
						 const vector<Matx<double,6,6>> & U,	// ���룺m��Uj���󣬽���ͼ������й�
						 const vector<Matx<double,3,3>> & V,	// ���룺n��Vi���󣬽����ռ�������й�
						 const vector<Matx<double,6,3>> & W,	// ���룺l��Wij����ͬʱ���ռ�㼰��۲�ͼ���й�
						 const Matx<double,1,1> & Q,			// ���룺Ψһһ��Q����ֻ���������й�
						 const vector<Matx<double,1,6>> & G,	// ���룺m��Gj����ͬʱ�Ͷ��м�����ͼ������й�
						 const vector<Matx<double,1,3>> & H,	// ���룺n��Hi����ͬʱ�͹���ͼ������Լ�����й�
						 vector<Matx<double,6,6>> & cov_a,		// �����m��ͼ����в�����Э������
						 vector<Matx<double,3,3>> & cov_b,		// �����n���ռ��������Э������
						 Matx<double,1,1> & cov_c,				// �������������Э������
						 vector<Matx<double,1,6>> & cov_ca		// �����ͼ�񹲲����͸�ͼ����в���֮���Э������
						 );

void covarianceSBA_wj_cj_XiYiZi(const vector<Point3d> & XYZs,			// ���룺n���ռ������
								const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
								const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
								const vector<Matx31d> & ts,				// ���룺m��ͼ��ƽ������
								const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
								const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
								const vector<Point2d> & xys,			// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
								const vector<Matx22d> & covInvs,		// ���룺l�������������Э�������������
								const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
								const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
								const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
								vector<Matx<double,6,6>> & cov_a,		// �����m��ͼ����в�����Э������
								vector<Matx<double,3,3>> & cov_b		// �����n���ռ��������Э������
								);

void covarianceSBA_f_wj_cj_XiYiZi(const vector<Point3d> & XYZs,				// ���룺n���ռ������
								  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
								  const vector<Matx33d> & Rs,				// ���룺m��ͼ����ת����
								  const vector<Matx31d> & ts,				// ���룺m��ͼ��ƽ������
								  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
								  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
								  const vector<Point2d> & xys,				// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
								  const vector<Matx22d> & covInvs,			// ���룺l�������������Э�������������
								  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
								  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
								  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
								  vector<Matx<double,6,6>> & cov_a,			// �����m��ͼ����в�����Э������
								  vector<Matx<double,3,3>> & cov_b,			// �����n���ռ��������Э������
								  Matx<double,1,1> & cov_c,					// �������������Э������
								  vector<Matx<double,1,6>> & cov_ca			// �����ͼ�񹲲����͸�ͼ����в���֮���Э������
								  );

//////////////////////////////////////////////////////////////////////////

void j_f_fxfycxcys_w_t_k1k2k3k4k5(const vector<Point3d> & vWrdPts,						// ���룺		���Ƶ�����
								  const vector<Point2d> & vImgPts,						// ���룺		���Ƶ�۲��������
								  const Matx33d & mK,									// ��ǰ���ڲ�������
								  const Matx33d & mR,									// ��ǰ����̬����
								  const Matx31d & mt,									// ��ǰ��ƽ����������
								  double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
								  int distType,											// ������ͣ�0 weng's, 1 brown's
								  Mat & J,												// �����	Jacobian����
								  Mat & f,												// �����	������Ŀ�꺯��ֵ
								  vector<double> & vds									// 
								  );

void j_f_fxfycxcy_w_t_k1k2k3k4k5(const vector<Point3d> & vWrdPts,						// ���룺		���Ƶ�����
								 const vector<Point2d> & vImgPts,						// ���룺		���Ƶ�۲��������
								 const Matx33d & mK,									// ��ǰ���ڲ�������
								 const Matx33d & mR,									// ��ǰ����̬����
								 const Matx31d & mt,									// ��ǰ��ƽ����������
								 double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
								 int distType,											// ������ͣ�0 weng's, 1 brown's
								 Mat & J,												// �����	Jacobian����
								 Mat & f,												// �����	������Ŀ�꺯��ֵ
								 vector<double> & vds									// 
								 );

void j_f_fcxcy_w_t_k1k2k3k4k5(const vector<Point3d> & vWrdPts,						// ���룺		���Ƶ�����
							  const vector<Point2d> & vImgPts,						// ���룺		���Ƶ�۲��������
							  const Matx33d & mK,									// ��ǰ���ڲ�������
							  const Matx33d & mR,									// ��ǰ����̬����
							  const Matx31d & mt,									// ��ǰ��ƽ����������
							  double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
							  int distType,											// ������ͣ�0 weng's, 1 brown's
							  Mat & J,												// �����	Jacobian����
							  Mat & f,												// �����	������Ŀ�꺯��ֵ
							  vector<double> & vds									// 
							  );

void j_f_f_w_t_k1k2k3k4k5(const vector<Point3d> & vWrdPts,						// ���룺		���Ƶ�����
						  const vector<Point2d> & vImgPts,						// ���룺		���Ƶ�۲��������
						  const Matx33d & mK,									// ��ǰ���ڲ�������
						  const Matx33d & mR,									// ��ǰ����̬����
						  const Matx31d & mt,									// ��ǰ��ƽ����������
						  double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
						  int distType,											// ������ͣ�0 weng's, 1 brown's
						  Mat & J,												// �����	Jacobian����
						  Mat & f,												// �����	������Ŀ�꺯��ֵ
						  vector<double> & vds									// 
						  );

void j_f_fxfycxcy_w_t_k1(const vector<Point3d> & vWrdPts,						// ���룺		���Ƶ�����
						 const vector<Point2d> & vImgPts,						// ���룺		���Ƶ�۲��������
						 const Matx33d & mK,									// ��ǰ���ڲ�������
						 const Matx33d & mR,									// ��ǰ����̬����
						 const Matx31d & mt,									// ��ǰ��ƽ����������
						 double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
						 int distType,											// ������ͣ�0 weng's, 1 brown's
						 Mat & J,												// �����	Jacobian����
						 Mat & f,												// �����	������Ŀ�꺯��ֵ
						 vector<double> & vds									// 
						 );

void j_f_fcxcy_w_t_k1(const vector<Point3d> & vWrdPts,						// ���룺		���Ƶ�����
					  const vector<Point2d> & vImgPts,						// ���룺		���Ƶ�۲��������
					  const Matx33d & mK,									// ��ǰ���ڲ�������
					  const Matx33d & mR,									// ��ǰ����̬����
					  const Matx31d & mt,									// ��ǰ��ƽ����������
					  double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
					  int distType,											// ������ͣ�0 weng's, 1 brown's
					  Mat & J,												// �����	Jacobian����
					  Mat & f,												// �����	������Ŀ�꺯��ֵ
					  vector<double> & vds									// 
					  );

void j_f_fxfycxcy_w_t_k1k2(const vector<Point3d> & vWrdPts,						// ���룺		���Ƶ�����
						   const vector<Point2d> & vImgPts,						// ���룺		���Ƶ�۲��������
						   const Matx33d & mK,									// ��ǰ���ڲ�������
						   const Matx33d & mR,									// ��ǰ����̬����
						   const Matx31d & mt,									// ��ǰ��ƽ����������
						   double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
						   int distType,										// ������ͣ�0 weng's, 1 brown's
						   Mat & J,												// �����	Jacobian����
						   Mat & f,												// �����	������Ŀ�꺯��ֵ
						   vector<double> & vds									// 
						   );

void j_f_fcxcy_w_t_k1k2(const vector<Point3d> & vWrdPts,					// ���룺		���Ƶ�����
						const vector<Point2d> & vImgPts,					// ���룺		���Ƶ�۲��������
						const Matx33d & mK,									// ��ǰ���ڲ�������
						const Matx33d & mR,									// ��ǰ����̬����
						const Matx31d & mt,									// ��ǰ��ƽ����������
						double k1,double k2,double k3, double k4, double k5,// ��ǰ�����ϵ������
						int distType,										// ������ͣ�0 weng's, 1 brown's
						Mat & J,											// �����	Jacobian����
						Mat & f,											// �����	������Ŀ�꺯��ֵ
						vector<double> & vds								// 
						);

// Matx<double,2,16> j_f_fxfycxcys_w_t_k1k2k3k4k5_weng(double X, double Y, double Z,	// �ÿ��Ƶ������
// 													double x, double y,				// �ÿ��Ƶ��ʵ�ʹ۲��������
// 													const Matx33d & mK,				// ��ǰ���ڲ�������
// 													const Matx33d & mR,				// ��ǰ����̬����
// 													const Matx31d & mt,				// ��ǰ��ƽ����������
// 													double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
// 													double & dx, double & dy		// ��ǰ�����µ���ͶӰ�в�
// 													);

// Matx<double,2,16> j_f_fxfycxcys_w_t_k1k2k3k4k5_brown(double X, double Y, double Z,	// �ÿ��Ƶ������
// 													 double x, double y,			// �ÿ��Ƶ��ʵ�ʹ۲��������
// 													 const Matx33d & mK,			// ��ǰ���ڲ�������
// 													 const Matx33d & mR,			// ��ǰ����̬����
// 													 const Matx31d & mt,			// ��ǰ��ƽ����������
// 													 double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
// 													 double & dx, double & dy		// ��ǰ�����µ���ͶӰ�в�
// 													 );

// void j_f_fxfycxcy_w_t_k1k2k3k4k5_weng(const vector<Point3d> & vWrdPts,						// ���룺		���Ƶ�����
// 									  const vector<Point2d> & vImgPts,						// ���룺		���Ƶ�۲��������
// 									  const Matx33d & mK,									// ��ǰ���ڲ�������
// 									  const Matx33d & mR,									// ��ǰ����̬����
// 									  const Matx31d & mt,									// ��ǰ��ƽ����������
// 									  double k1,double k2,double k3, double k4, double k5,	// ��ǰ�����ϵ������
// 									  Mat & J,												// �����	Jacobian����
// 									  Mat & f,												// �����	������Ŀ�꺯��ֵ
// 									  vector<double> & vds									// 
// 									  );
// 
// void j_f_fxfycxcys_w_t_k1k2k3k4k5_brown(const vector<Point3d> & vWrdPts,					// ���룺		���Ƶ�����
// 									    const vector<Point2d> & vImgPts,					// ���룺		���Ƶ�۲��������
// 									    const Matx33d & mK,									// ��ǰ���ڲ�������
// 									    const Matx33d & mR,									// ��ǰ����̬����
// 									    const Matx31d & mt,									// ��ǰ��ƽ����������
// 									    double k1,double k2,double k3, double k4, double k5,// ��ǰ�����ϵ������
// 									    Mat & J,											// �����	Jacobian����
// 									    Mat & f,											// �����	������Ŀ�꺯��ֵ
// 									    vector<double> & vds								// 
// 									    );

}

namespace distortions
{

// �����һ����������
void dudv_weng(double u, double v, double k1, double k2, double k3, double k4, double k5, double & du, double & dv);

// �����һ����������
// examined on 2015.04.22
void dudv_brown(double u, double v, double k1, double k2, double k3, double k4, double k5, double & du, double & dv);

// ������������
void dxdy_weng(double fx, double fy, double s, double u, double v, double k1, double k2, double k3, double k4, double k5, double & dx, double & dy);

// ������������
// examined on 2015.04.22
void dxdy_brown(double fx, double fy, double s, double u, double v, double k1, double k2, double k3, double k4, double k5, double & dx, double & dy);

// �Դ�������������ȥ����
void remove_weng(double fx, double fy, double cx, double cy, double s,
				 double k1, double k2, double k3, double k4, double k5,
	             double dist_x, double dist_y,
				 double & ideal_x, double & ideal_y,
				 int maxIter = 32, 
				 double eps = 1e-10
				 );

// �Դ�������������ȥ����
void remove_brown(double fx, double fy, double cx, double cy, double s,
				  double k1, double k2, double k3, double k4, double k5,
	              double dist_x, double dist_y,
				  double & ideal_x, double & ideal_y,
				  int maxIter = 32, 
				  double eps = 1e-10
				  );

}

namespace calib
{

// �������ڡ�Matrix Computations 3rd Edition��һ��P.216�е�Algorithm 5.1.3 (Computes Givens c and s)
// ���������[a; b]'����ʹ��[c s; -s c]' * [a; b]' = [r; 0]'������cos��sin
void Givens(double a, double b, double & c, double & s);

// ��m��n�ľ���A����RQ�ֽ⣨Ҫ��m<=n����A = RQ������QΪn��n����������RΪm��n�ģ������Խ���Ԫ�ؽ�Ϊ���������Ǿ���
// ���õ���Givens��ת����ʵ�ֵģ�����Ҫ��m<=n��ԭ���ڱʼǱ�������ϸ����
void RQ_Givens(const Mat & A, Mat & R, Mat & Q);

// ��3��3�ľ���ʵʩRQ�ֽ�
void RQ3x3_Givens(const Matx33d & A, Matx33d & R, Matx33d & Q);

// �����������ת���󣬷���һ�� 3 ά����������Ϊ ��|v|������ v Ϊ��ת��ĵ�λ�������� Ϊ��ת����
Matx31d converse_R_rotvec(const Matx33d & mR);

// ����ת����ת��Ϊ��ת����
Matx33d converse_rotvec_R(double rv1, double rv2, double rv3);
Matx33d converse_rotvec_R(const Matx31d & v);
Matx33d converse_rotvec_R(const Matx13d & v);

// ������Ԫ����������ת����
Matx33d converse_quaternion_R(double a, double b, double c, double d);

// zhaokunz, 20150107, <multiple view geometry in computer vision 2nd edition> p.107
// Normalizing transformations based on isotropic scaling
// return 3*3 transformation matrix
Matx33d normalize_2d(const vector<Point2f> & pts, vector<Point2f> & pts_t);

// zhaokunz, 20150107, <multiple view geometry in computer vision 2nd edition> p.107
// Normalizing transformations based on isotropic scaling
// return 3*3 transformation matrix
// tested on 2015.04.22
Matx33d normalize_2d(const vector<Point2d> & pts, vector<Point2d> & pts_t);

// 20150421�������пռ��ƽ������������ϵ�������е㵽���ĵ�ƽ������Ϊ3^0.5
Matx44d normalize_3d(const vector<Point3f> & pts, vector<Point3f> & pts_t);

// 20150421�������пռ��ƽ������������ϵ�������е㵽���ĵ�ƽ������Ϊ3^0.5
// tested on 2015.04.22
Matx44d normalize_3d(const vector<Point3d> & pts, vector<Point3d> & pts_t);

Matx33d cross_mat(const Matx31d & v);
Matx33d cross_mat(const Matx13d & v);

// �������K����������
// tested on 2015.04.22
Matx33d invK(const Matx33d & mK);
Matx33d invK(double fx, double fy, double cx, double cy, double s);

// wx=PX,����PΪ3��4�ľ���XΪ4��1������
Matx34d dlt_34(const Mat & mX,	// ���룺	4��n �ľ���
			   const Mat & mx	// ���룺	2��n �ľ���
			   );

// wx=HX,����HΪ3��3�ľ���XΪ3��1������
Matx33d dlt_33(const Mat & mX,	// ���룺	3��n �ľ���
			   const Mat & mx	// ���룺	2��n �ľ���
			   );

// �����Ӧ�����Խ�aH�зֽ������ڲκ���ת���󣬲����س߶�����a
double decomp_KR(const Matx33d & mKR,	// ���룺	3��3 ��aKR����Ҳ�������Ӧ
				 Matx33d & mK,			// �����	3��3 ������ڲξ���
				 Matx33d & mR			// �����	3��3 �������ת����
				 );

// ��ͶӰ��������Խ�aP�зֽ������������
void decomp_P(const Matx34d & mP,	// ���룺	3��4 ��ͶӰ����aP
			  Matx33d & mK,			// �����	3��3 ������ڲξ���
			  Matx33d & mR,			// �����	3��3 �������ת����
			  Matx31d & mt			// �����	3��1 �����ƽ������
			  );

// �����Խ�a[R|t]�зֽ����������
void decomp_R_t(const Matx34d & mR_t,	// ���룺	3��4 ��a[R|t]
				Matx33d & mR,			// �����	3��3 �������ת����
				Matx31d & mt			// �����	3��1 �����ƽ������
				);

// �����Խ�aK[r1 r2 t]�зֽ����������
void decomp_H(const Matx33d & mH,	// ���룺	3��3 ��aK[r1 r2 t]
			  const Matx33d & mK,	// ���룺	��֪�� 3��3 ���ڲξ���
			  Matx33d & mR,			// �����	3��3 �������ת����
			  Matx31d & mt			// �����	3��1 �����ƽ������
			  );

// ����6�����Ͽ��Ƶ����Ա궨���ͶӰ����
Matx34d calib_P(const vector<Point3d> & pts3d, const vector<Point2d> & pts2d);

// ����4���Ͽ��Ƶ�͹���λ�����Ա궨��������ӦH=KR
Matx33d calib_KR(const vector<Point3d> & pts3d, const vector<Point2d> & pts2d, const Point3d & c);

}

namespace optim
{
void optim_lm_fxfycxcys_w_t_k1k2k3k4k5(const vector<Point3d> & vWrdPts,	// ���룺		���Ƶ�����
									   const vector<Point2d> & vImgPts,	// ���룺		���Ƶ�۲��������
									   Matx33d & mK,					// ����������	���Ż����Ż�����ڲ�������
									   Matx33d & mR,					// ����������	���Ż����Ż������ת����
									   Matx31d & mt,					// ����������	���Ż����Ż����ƽ������
									   double * dist,					// ����������	double dist[5]�����Ż����Ż����weng's���ϵ��
									   int distType = 0,				// ���룺	0 weng's, 1 brown's
									   double * info = NULL,			// output:	runtime info, 5-vector
																		// info[0]:	the initial reprojection error
																		// info[1]:	the final reprojection error
																		// info[2]: final max gradient
																		// info[3]: the number of iterations
																		// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
									   double tau = 1.0E-3,				// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
									   int maxIter = 15,				// input:	the maximum number of iterations
									   double eps1 = 1.0E-8,			// input:	threshold
									   double eps2 = 1.0E-12			// input:	threshold
									   );

void optim_lm_fxfycxcy_w_t_k1k2k3k4k5(const vector<Point3d> & vWrdPts,	// ���룺		���Ƶ�����
									  const vector<Point2d> & vImgPts,	// ���룺		���Ƶ�۲��������
									  Matx33d & mK,						// ����������	���Ż����Ż�����ڲ�������
									  Matx33d & mR,						// ����������	���Ż����Ż������ת����
									  Matx31d & mt,						// ����������	���Ż����Ż����ƽ������
									  double * dist,					// ����������	double dist[5]�����Ż����Ż����weng's���ϵ��
									  int distType = 0,					// ���룺	0 weng's, 1 brown's
									  double * info = NULL,				// output:	runtime info, 5-vector
																		// info[0]:	the initial reprojection error
																		// info[1]:	the final reprojection error
																		// info[2]: final max gradient
																		// info[3]: the number of iterations
																		// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
									  double tau = 1.0E-3,				// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
									  int maxIter = 15,					// input:	the maximum number of iterations
									  double eps1 = 1.0E-8,				// input:	threshold
									  double eps2 = 1.0E-12				// input:	threshold
									  );

void optim_lm_fcxcy_w_t_k1k2k3k4k5(const vector<Point3d> & vWrdPts,	// ���룺		���Ƶ�����
								   const vector<Point2d> & vImgPts,	// ���룺		���Ƶ�۲��������
								   Matx33d & mK,					// ����������	���Ż����Ż�����ڲ�������
								   Matx33d & mR,					// ����������	���Ż����Ż������ת����
								   Matx31d & mt,					// ����������	���Ż����Ż����ƽ������
								   double * dist,					// ����������	double dist[5]�����Ż����Ż����weng's���ϵ��
								   int distType = 0,				// ���룺	0 weng's, 1 brown's
								   double * info = NULL,			// output:	runtime info, 5-vector
																	// info[0]:	the initial reprojection error
																	// info[1]:	the final reprojection error
																	// info[2]: final max gradient
																	// info[3]: the number of iterations
																	// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
								   double tau = 1.0E-3,				// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
								   int maxIter = 15,				// input:	the maximum number of iterations
								   double eps1 = 1.0E-8,			// input:	threshold
								   double eps2 = 1.0E-12			// input:	threshold
								   );

void optim_lm_f_w_t_k1k2k3k4k5(const vector<Point3d> & vWrdPts,	// ���룺		���Ƶ�����
							   const vector<Point2d> & vImgPts,	// ���룺		���Ƶ�۲��������
							   Matx33d & mK,					// ����������	���Ż����Ż�����ڲ�������
							   Matx33d & mR,					// ����������	���Ż����Ż������ת����
							   Matx31d & mt,					// ����������	���Ż����Ż����ƽ������
							   double * dist,					// ����������	double dist[5]�����Ż����Ż����weng's���ϵ��
							   int distType = 0,				// ���룺	0 weng's, 1 brown's
							   double * info = NULL,			// output:	runtime info, 5-vector
																// info[0]:	the initial reprojection error
																// info[1]:	the final reprojection error
																// info[2]: final max gradient
																// info[3]: the number of iterations
																// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
							   double tau = 1.0E-3,				// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
							   int maxIter = 15,				// input:	the maximum number of iterations
							   double eps1 = 1.0E-8,			// input:	threshold
							   double eps2 = 1.0E-12			// input:	threshold
							   );

void optim_lm_fxfycxcy_w_t_k1(const vector<Point3d> & vWrdPts,	// ���룺		���Ƶ�����
							  const vector<Point2d> & vImgPts,	// ���룺		���Ƶ�۲��������
							  Matx33d & mK,						// ����������	���Ż����Ż�����ڲ�������
							  Matx33d & mR,						// ����������	���Ż����Ż������ת����
							  Matx31d & mt,						// ����������	���Ż����Ż����ƽ������
							  double * dist,					// ����������	double dist[5]�����Ż����Ż����weng's���ϵ��
							  int distType = 0,					// ���룺	0 weng's, 1 brown's
							  double * info = NULL,				// output:	runtime info, 5-vector
																// info[0]:	the initial reprojection error
																// info[1]:	the final reprojection error
																// info[2]: final max gradient
																// info[3]: the number of iterations
																// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
							  double tau = 1.0E-3,				// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
							  int maxIter = 15,					// input:	the maximum number of iterations
							  double eps1 = 1.0E-8,				// input:	threshold
							  double eps2 = 1.0E-12				// input:	threshold
							  );

void optim_lm_fcxcy_w_t_k1(const vector<Point3d> & vWrdPts,	// ���룺		���Ƶ�����
						   const vector<Point2d> & vImgPts,	// ���룺		���Ƶ�۲��������
						   Matx33d & mK,					// ����������	���Ż����Ż�����ڲ�������
						   Matx33d & mR,					// ����������	���Ż����Ż������ת����
						   Matx31d & mt,					// ����������	���Ż����Ż����ƽ������
						   double * dist,					// ����������	double dist[5]�����Ż����Ż����weng's���ϵ��
						   int distType = 0,				// ���룺	0 weng's, 1 brown's
						   double * info = NULL,			// output:	runtime info, 5-vector
															// info[0]:	the initial reprojection error
															// info[1]:	the final reprojection error
															// info[2]: final max gradient
															// info[3]: the number of iterations
															// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
						   double tau = 1.0E-3,				// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
						   int maxIter = 15,				// input:	the maximum number of iterations
						   double eps1 = 1.0E-8,			// input:	threshold
						   double eps2 = 1.0E-12			// input:	threshold
						   );

void optim_lm_fxfycxcy_w_t_k1k2(const vector<Point3d> & vWrdPts,// ���룺		���Ƶ�����
								const vector<Point2d> & vImgPts,// ���룺		���Ƶ�۲��������
								Matx33d & mK,					// ����������	���Ż����Ż�����ڲ�������
								Matx33d & mR,					// ����������	���Ż����Ż������ת����
								Matx31d & mt,					// ����������	���Ż����Ż����ƽ������
								double * dist,					// ����������	double dist[5]�����Ż����Ż����weng's���ϵ��
								int distType = 0,				// ���룺	0 weng's, 1 brown's
								double * info = NULL,			// output:	runtime info, 5-vector
																// info[0]:	the initial reprojection error
																// info[1]:	the final reprojection error
																// info[2]: final max gradient
																// info[3]: the number of iterations
																// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
								double tau = 1.0E-3,			// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
								int maxIter = 15,				// input:	the maximum number of iterations
								double eps1 = 1.0E-8,			// input:	threshold
								double eps2 = 1.0E-12			// input:	threshold
								);

void optim_lm_fcxcy_w_t_k1k2(const vector<Point3d> & vWrdPts,	// ���룺		���Ƶ�����
							 const vector<Point2d> & vImgPts,	// ���룺		���Ƶ�۲��������
						     Matx33d & mK,						// ����������	���Ż����Ż�����ڲ�������
						     Matx33d & mR,						// ����������	���Ż����Ż������ת����
						     Matx31d & mt,						// ����������	���Ż����Ż����ƽ������
						     double * dist,						// ����������	double dist[5]�����Ż����Ż����weng's���ϵ��
						     int distType = 0,					// ���룺	0 weng's, 1 brown's
						     double * info = NULL,				// output:	runtime info, 5-vector
																// info[0]:	the initial reprojection error
																// info[1]:	the final reprojection error
																// info[2]: final max gradient
																// info[3]: the number of iterations
																// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
						     double tau = 1.0E-3,				// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
						     int maxIter = 15,					// input:	the maximum number of iterations
						     double eps1 = 1.0E-8,				// input:	threshold
						     double eps2 = 1.0E-12				// input:	threshold
						     );

// void optim_lm_fxfycxcys_w_t_k1k2k3k4k5_weng(const vector<Point3d> & vWrdPts,	// ���룺		���Ƶ�����
// 											const vector<Point2d> & vImgPts,	// ���룺		���Ƶ�۲��������
// 											Matx33d & mK,						// ����������	���Ż����Ż�����ڲ�������
// 											Matx33d & mR,						// ����������	���Ż����Ż������ת����
// 											Matx31d & mt,						// ����������	���Ż����Ż����ƽ������
// 											double * dist,						// ����������	double dist[5]�����Ż����Ż����weng's���ϵ��
// 											double * info = NULL,				// output:	runtime info, 5-vector
// 																				// info[0]:	the initial reprojection error
// 																				// info[1]:	the final reprojection error
// 																				// info[2]: final max gradient
// 																				// info[3]: the number of iterations
// 																				// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
// 											double tau = 1.0E-3,				// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
// 											int maxIter = 15,					// input:	the maximum number of iterations
// 											double eps1 = 1.0E-8,				// input:	threshold
// 											double eps2 = 1.0E-12				// input:	threshold
// 											);

// void optim_lm_fxfycxcys_w_t_k1k2k3k4k5_brown(const vector<Point3d> & vWrdPts,	// ���룺		���Ƶ�����
// 											 const vector<Point2d> & vImgPts,	// ���룺		���Ƶ�۲��������
// 											 Matx33d & mK,						// ����������	���Ż����Ż�����ڲ�������
// 											 Matx33d & mR,						// ����������	���Ż����Ż������ת����
// 											 Matx31d & mt,						// ����������	���Ż����Ż����ƽ������
// 											 double * dist,						// ����������	double dist[5]�����Ż����Ż����weng's���ϵ��
// 											 double * info = NULL,				// output:	runtime info, 5-vector
// 																				// info[0]:	the initial reprojection error
// 																				// info[1]:	the final reprojection error
// 																				// info[2]: final max gradient
// 																				// info[3]: the number of iterations
// 																				// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
// 											 double tau = 1.0E-3,				// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
// 											 int maxIter = 15,					// input:	the maximum number of iterations
// 											 double eps1 = 1.0E-8,				// input:	threshold
// 											 double eps2 = 1.0E-12				// input:	threshold
// 											 );
}

namespace SfM_ZZK
{
// optimize Ri based on Rotation Averaging using Newton-Raphson method
// ��ϸ�ο� Govindu 04 <Lie-algebraic averaging for globally consistent motion estimation> �е� Algorithm A2
void optim_nr_Ri_Govindu04(const vector<Matx33d> & vRijs,	// ���룺		���й۲�������ת����
						   const vector<Point2i> & vijs,	// ���룺		ÿ�������ת�����ij�����ţ���0��ʼ
						   vector<Matx33d> & vRis,			// ����&�����	����ͼ��ĳ�ʼ��ת�����Լ��Ż������ת����
						   int idx_ref,						// ���룺		�����Ĳο�ͼ������������û�в����Ĳο�ͼ�񣬾����������Ϊ-1
						   int * nIter = NULL,				// �����		ʵ�ʵ�������
						   double * residue = NULL,			// �����		���յĲв��С
						   int max_iter = 32,				// ���룺		����������
						   double xEps = 1.0E-12,			// ���룺		��ֹ����
						   double fEps = 1.0E-12			// ���룺		��ֹ����
						   );

// optimize Ri based on Rotation Averaging using Newton-Raphson method
// ��ϸ�ο� Govindu 04 <Lie-algebraic averaging for globally consistent motion estimation> �е� Algorithm A2
void optim_nr_Ri(const vector<Matx33d> & vRijs,	// ���룺		���й۲�������ת����
				 const vector<Point2i> & vijs,	// ���룺		ÿ�������ת�����ij�����ţ���0��ʼ
				 vector<Matx33d> & vRis,		// ����&�����	����ͼ��ĳ�ʼ��ת�����Լ��Ż������ת����
				 int idx_ref,					// ���룺		�����Ĳο�ͼ������������û�в����Ĳο�ͼ�񣬾����������Ϊ-1
				 int * nIter = NULL,			// �����		ʵ�ʵ�������
				 double * residue = NULL,		// �����		���յĲв��С
				 int max_iter = 32,				// ���룺		����������
				 double xEps = 1.0E-12,			// ���룺		��ֹ����
				 double fEps = 1.0E-12			// ���룺		��ֹ����
				 );

// optimize Ri based on Rotation Averaging using Gauss-Newton method
// ��ϸ�ο� Govindu 04 <Lie-algebraic averaging for globally consistent motion estimation> �е� Algorithm A2
void optim_gn_Ri(const vector<Matx33d> & vRijs,	// ���룺		���й۲�������ת����
				 const vector<Point2i> & vijs,	// ���룺		ÿ�������ת�����ij�����ţ���0��ʼ
				 vector<Matx33d> & vRis,		// ����&�����	����ͼ��ĳ�ʼ��ת�����Լ��Ż������ת����
				 int idx_ref,					// ���룺		�����Ĳο�ͼ������������û�в����Ĳο�ͼ�񣬾����������Ϊ-1
				 int * nIter = NULL,			// �����		ʵ�ʵ�������
				 double * residue = NULL,		// �����		���յĲв��С
				 int max_iter = 32,				// ���룺		����������
				 double xEps = 1.0E-12,			// ���룺		��ֹ����
				 double fEps = 1.0E-12			// ���룺		��ֹ����
				 );

void optim_lm_Ri(const vector<Matx33d> & vRijs,	// ���룺		���й۲�������ת����
				 const vector<Point2i> & vijs,	// ���룺		ÿ�������ת�����ij�����ţ���0��ʼ
				 vector<Matx33d> & vRis,		// ����&�����	����ͼ��ĳ�ʼ��ת�����Լ��Ż������ת����
				 int idx_ref,					// ���룺		�����Ĳο�ͼ������������û�в����Ĳο�ͼ�񣬾����������Ϊ-1
				 double * info = NULL,			// output:	runtime info, 5-vector
												// info[0]:	the initial reprojection error
												// info[1]:	the final reprojection error
												// info[2]: final max gradient
												// info[3]: the number of iterations
												// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
				 double tau = 1.0E-3,			// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
				 int maxIter = 64,				// input:	the maximum number of iterations
				 double eps1 = 1.0E-8,			// input:	threshold
				 double eps2 = 1.0E-12			// input:	threshold
				 );

}

namespace SBA_ZZK
{

void optim_sparse_lm_wj_tj_XiYiZiWi(vector<Point3d> & XYZs,					// ����������n���ռ������
								    const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
								    vector<Matx33d> & Rs,					// ����������m��ͼ����ת����
								    vector<Matx31d> & ts,					// ����������m��ͼ��ƽ������
								    const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
								    const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
								    const vector<Point2d> & xys,			// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
								    const vector<Matx22d> & covInvs,		// ���룺l�������������Э�������������
								    const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
								    const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
								    const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
									double * info = NULL,					// output:	runtime info, 5-vector
																			// info[0]:	the initial reprojection error
																			// info[1]:	the final reprojection error
																			// info[2]: final max gradient
																			// info[3]: the number of iterations
																			// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
									double tau = 1.0E-3,					// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
									int maxIter = 64,						// input:	the maximum number of iterations
									double eps1 = 1.0E-8,					// input:	threshold
									double eps2 = 1.0E-12					// input:	threshold
								    );

void optim_sparse_lm_wj_tj_XiYiZi(vector<Point3d> & XYZs,					// ����������n���ռ������
								  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
								  vector<Matx33d> & Rs,						// ����������m��ͼ����ת����
								  vector<Matx31d> & ts,						// ����������m��ͼ��ƽ������
								  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
								  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
								  const vector<Point2d> & xys,				// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
								  const vector<Matx22d> & covInvs,			// ���룺l�������������Э�������������
								  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
								  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
								  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
								  double * info = NULL,						// output:	runtime info, 5-vector
																			// info[0]:	the initial reprojection error
																			// info[1]:	the final reprojection error
																			// info[2]: final max gradient
																			// info[3]: the number of iterations
																			// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
								  double tau = 1.0E-3,						// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
								  int maxIter = 64,							// input:	the maximum number of iterations
								  double eps1 = 1.0E-8,						// input:	threshold
								  double eps2 = 1.0E-12						// input:	threshold
								  );

void optim_sparse_lm_wj_cj_XiYiZiWi(vector<Point3d> & XYZs,					// ����������n���ռ������
								    const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
								    vector<Matx33d> & Rs,					// ����������m��ͼ����ת����
								    vector<Matx31d> & ts,					// ����������m��ͼ��ƽ������
								    const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
								    const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
								    const vector<Point2d> & xys,			// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
								    const vector<Matx22d> & covInvs,		// ���룺l�������������Э�������������
								    const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
								    const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
								    const SparseMat & ptrMat,				// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
									double * info = NULL,					// output:	runtime info, 5-vector
																			// info[0]:	the initial reprojection error
																			// info[1]:	the final reprojection error
																			// info[2]: final max gradient
																			// info[3]: the number of iterations
																			// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
									double tau = 1.0E-3,					// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
									int maxIter = 64,						// input:	the maximum number of iterations
									double eps1 = 1.0E-8,					// input:	threshold
									double eps2 = 1.0E-12					// input:	threshold
								    );

void optim_sparse_lm_wj_cj_XiYiZi(vector<Point3d> & XYZs,					// ����������n���ռ������
								  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
								  vector<Matx33d> & Rs,						// ����������m��ͼ����ת����
								  vector<Matx31d> & ts,						// ����������m��ͼ��ƽ������
								  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
								  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
								  const vector<Point2d> & xys,				// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
								  const vector<Matx22d> & covInvs,			// ���룺l�������������Э�������������
								  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
								  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
								  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
								  double * info = NULL,						// output:	runtime info, 5-vector
																			// info[0]:	the initial reprojection error
																			// info[1]:	the final reprojection error
																			// info[2]: final max gradient
																			// info[3]: the number of iterations
																			// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
								  double tau = 1.0E-3,						// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
								  int maxIter = 64,							// input:	the maximum number of iterations
								  double eps1 = 1.0E-8,						// input:	threshold
								  double eps2 = 1.0E-12						// input:	threshold
								  );

void optim_sparse_lm_f_wj_tj_XiYiZiWi(vector<Point3d> & XYZs,					// ����������n���ռ������
									  vector<Matx33d> & Ks,						// ����������m��ͼ���ڲ�������
								      vector<Matx33d> & Rs,						// ����������m��ͼ����ת����
								      vector<Matx31d> & ts,						// ����������m��ͼ��ƽ������
								      const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
								      const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
								      const vector<Point2d> & xys,				// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
								      const vector<Matx22d> & covInvs,			// ���룺l�������������Э�������������
								      const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
								      const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
								      const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
									  double * info = NULL,						// output:	runtime info, 5-vector
																				// info[0]:	the initial reprojection error
																				// info[1]:	the final reprojection error
																				// info[2]: final max gradient
																				// info[3]: the number of iterations
																				// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
									  double tau = 1.0E-3,						// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
									  int maxIter = 64,							// input:	the maximum number of iterations
									  double eps1 = 1.0E-8,						// input:	threshold
									  double eps2 = 1.0E-12						// input:	threshold
								      );

void optim_sparse_lm_f_wj_tj_XiYiZiWi_c_fixedBaseline(vector<Point3d> & XYZs,					// ����������n���ռ������
													  vector<Matx33d> & Ks,						// ����������m��ͼ���ڲ�������
													  vector<Matx33d> & Rs,						// ����������m��ͼ����ת����
													  vector<Matx31d> & ts,						// ����������m��ͼ��ƽ������
													  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
													  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
													  const vector<Point2d> & xys,				// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
													  const vector<Matx22d> & covInvs,			// ���룺l�������������Э�������������
													  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
													  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
													  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Aij��Bij��eij�ڸ��������д洢��λ������
													  int k_fixedBaseLine,						// ���룺������ͼ��֮��Ļ��߹̶�������k �ǲ�������һ��
													  int j_fixedBaseLine,						// ���룺������ͼ��֮��Ļ��߹̶�������j �ǵ�����һ��
													  double d_fixedBaseLine,					// ���룺����ͼ��֮��Ĺ̶����߳���
													  double * info = NULL,						// output:	runtime info, 5-vector
																								// info[0]:	the initial reprojection error
																								// info[1]:	the final reprojection error
																								// info[2]: final max gradient
																								// info[3]: the number of iterations
																								// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
													  double tau = 1.0E-3,						// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
													  int maxIter = 64,							// input:	the maximum number of iterations
													  double eps1 = 1.0E-8,						// input:	threshold
													  double eps2 = 1.0E-12						// input:	threshold
													  );

// 20150722��ÿ��������������ο�ͼ�����ֵ������
void optim_sparse_lm_wj_tj_di(vector<Point3d> & XYZs,					// ����������n���ռ������
							  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
							  vector<Matx33d> & Rs,						// ����������m��ͼ����ת����
							  vector<Matx31d> & ts,						// ����������m��ͼ��ƽ������
							  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
							  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
							  const vector<Point2d> & xys,				// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
							  const vector<Matx22d> & covInvs,			// ���룺l�������������Э�������������
							  const vector<int> & ri_j,					// ���룺n���������Ĳο�ͼ���������һ�� i ����Ӧһ�� j
							  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
							  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
							  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Wij�ڸ��������д洢��λ������
							  double * info = NULL,						// output:	runtime info, 5-vector
																		// info[0]:	the initial reprojection error
																		// info[1]:	the final reprojection error
																		// info[2]: final max gradient
																		// info[3]: the number of iterations
																		// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
							  double tau = 1.0E-3,						// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
							  int maxIter = 64,							// input:	the maximum number of iterations
							  double eps1 = 1.0E-8,						// input:	threshold
							  double eps2 = 1.0E-12						// input:	threshold
							  );

// 20150728��ÿ��������������ο�ͼ�����ֵ������
// ÿ����������ȥ����һ�������������Ϊ�������룬�����ں����ڲ�����
void optim_sparse_lm_wj_tj_di(vector<Point3d> & XYZs,					// ����������n���ռ������
							  const vector<Matx33d> & Ks,				// ���룺m��ͼ���ڲ�������
							  vector<Matx33d> & Rs,						// ����������m��ͼ����ת����
							  vector<Matx31d> & ts,						// ����������m��ͼ��ƽ������
							  const vector<Matx<double,5,1>> & dists,	// ���룺m��ͼ�����ϵ��
							  const vector<int> & distTypes,			// ���룺m��ͼ������ϵ������
							  const vector<Point2d> & xys,				// ���룺l������ͼ���ϵ�������꣬������Ϊ m*n ��
							  const vector<Matx22d> & covInvs,			// ���룺l�������������Э�������������
							  const vector<Matx31d> & nxys,				// ���룺n��������������ο�ͼ��ϵ�еĹ۲����߷���Ҳ��ȥ����һ���������
							  const vector<int> & ri_j,					// ���룺n���������Ĳο�ͼ���������һ�� i ����Ӧһ�� j
							  const vector<uchar> & j_fixed,			// ���룺mά��������Щͼ��Ĳ����ǹ̶��ģ�j_fixed[j]=1�������ͼ�� j �����̶�����ô Aij = 0 �����κ����еĹ۲�� i ������
							  const vector<uchar> & i_fixed,			// ���룺nά��������Щ�ռ�������ǹ̶��ģ�i_fixed[i]=1��������� i ����̶�����ô Bij = 0 �����κι۲⵽�õ��ͼ�� j ������
							  const SparseMat & ptrMat,					// ���룺��һά�洢�����Ŀ��Ӿ���ptrMat(i,j)��������xij��xys�����д洢��λ���������Լ�Wij�ڸ��������д洢��λ������
							  double * info = NULL,						// output:	runtime info, 5-vector
																		// info[0]:	the initial reprojection error
																		// info[1]:	the final reprojection error
																		// info[2]: final max gradient
																		// info[3]: the number of iterations
																		// info[4]: the termination code, 0: small gradient; 1: small correction; 2: max iteration 
							  double tau = 1.0E-3,						// input:	The algorithm is not very sensitive to the choice of tau, but as a rule of thumb, one should use a small value, eg tau=1E-6 if x0 is believed to be a good approximation to real value, otherwise, use tau=1E-3 or even tau=1
							  int maxIter = 64,							// input:	the maximum number of iterations
							  double eps1 = 1.0E-8,						// input:	threshold
							  double eps2 = 1.0E-12						// input:	threshold
							  );

}