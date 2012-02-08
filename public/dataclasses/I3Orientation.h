/**
 * @version $Id$
 * @file I3Orientation.h
 * @date $Date$
 */

#ifndef I3ORIENTATION_H_INCLUDED
#define I3ORIENTATION_H_INCLUDED

#include <math.h>
#include <sstream>
#include "icetray/I3FrameObject.h"
#include "Utility.h"
#include "dataclasses/I3Constants.h"
#include "dataclasses/I3Quaternion.h"
#include "dataclasses/I3Direction.h"

static const unsigned i3orientation_version_ = 0;

/**
 * Stores an orientation. This is more than a direction
 * in that you also include the rotation around the direction
 * axis. Picture the three-finger right hand rule.
 * Your thumb points into the "direction", your index finger points
 * to the "right" and your middle finger to "front".
 */
class I3Orientation : public I3FrameObject
	{
	public:
		
		I3Orientation();
		
		/**
		 * Additional constructor: 6 arguments mean construct dir. with dir(x,y,z) and right(x,y,z)
		 */
		I3Orientation(double x_dir, double y_dir, double z_dir, double x_right, double y_right, double z_right);
		
		/**
		 * Additional constructor: 6 arguments mean construct dir. with dir(x,y,z) and right(x,y,z)
		 */
		I3Orientation(const I3Direction &dir, const I3Direction &right);
		
		/**
		 * Copy constructor
		 */
		I3Orientation(const I3Orientation& d);

		/**
		 * Assignment constructor from direction (will generate an arbitrary rotation angle)
		 */
		I3Orientation(const I3Direction& d)
		{
			SetOrientation(d);
		}
		
		virtual ~I3Orientation();
		
		//--------------

		/**
		 * Assignment operator from direction (will generate an arbitrary rotation angle)
		 */
		inline I3Orientation operator=(const I3Orientation& d)
		{
			SetOrientation(d);
			return (*this);
		}
		
		/**
		 * Assignment operator from orientation (will generate an arbitrary rotation angle)
		 */
		inline I3Orientation operator=(const I3Direction& d)
		{
			SetOrientation(d);
			return (*this);
		}
		
		//--------------
		
		/**
		 * Store direction from orientation d
		 */
		void SetOrientation(const I3Orientation& d);

		/**
		 * Store direction from a single direction d
		 * (this will generate an arbitrary "right" direction)
		 */
		void SetOrientation(const I3Direction& d);
		
		/**
		 * Store direction with x, y, z (3 arguments)
		 */
		void SetOrientation(double x_dir, double y_dir, double z_dir, double x_right, double y_right, double z_right);

		/**
		 * Store direction with x, y, z (3 arguments)
		 */
		void SetOrientation(const I3Direction &dir, const I3Direction &right);

		/**
		 * Store direction from a unit quaternion rotation the (0,0,1) vector
		 */
		void SetOrientationFromQuaternion(const I3Quaternion &q);
		
		/**
		 * Reset all elements of I3Orientation to NAN
		 */
		void ResetOrientation();

		//--------------

		/**
		 * Rotate a vector inside a coordinate system where z-axis==(0,0,1), x-axis==(1,0,0), y-axis=(0,1,0)
		 * to the system where z-axis==dir, x-axis==right, y-axis==front.
		 * This is the in-place version with 3 doubles for x,y,z.
		 */
		inline void RotVectorInPlace(double &x, double &y, double &z) const {
			rot_.rot3VectorInPlace(x,y,z);
		}
		
		//--------------
		
		/**
		 * Provide Zenith of direction
		 */
		inline double GetZenith() const {
			if (!isDirCalculated_) DoCalcDir();
			return zenithDir_;
		}

		inline double GetDirZenith() const {
			return GetZenith();
		}
		
		/**
		 * Provide Azimuth of direction
		 */
		inline double GetAzimuth() const {
			if (!isDirCalculated_) DoCalcDir();
			return azimuthDir_;
		}

		inline double GetDirAzimuth() const {
			return GetAzimuth();
		}
		
		/**
		 * Provide X of direction in cartesian ref frame
		 */
		inline double GetX() const {
			if (!isDirCalculated_) DoCalcDir();
			return xDir_;
		}

		inline double GetDirX() const {
			return GetX();
		}
		
		/**
		 * Provide Y of direction in cartesian ref frame
		 */
		inline double GetY() const {
			if (!isDirCalculated_) DoCalcDir();
			return yDir_;
		}

		inline double GetDirY() const {
			return GetY();
		}
		
		/**
		 * Provide Z of direction in cartesian ref frame
		 */
		inline double GetZ() const {
			if (!isDirCalculated_) DoCalcDir();
			return zDir_;
		}

		inline double GetDirZ() const {
			return GetZ();
		}

		/**
		 * Calculate "dir" direction
		 */
		inline I3Direction GetDir() const {
			if (!isDirCalculated_) DoCalcDir();
			return I3Direction(zenithDir_, azimuthDir_);
		}
		
		/**
		 * Calculate Theta of "dir" direction
		 */
		inline double CalcDirTheta() const {
			if (!isDirCalculated_) DoCalcDir();
			double theta = I3Constants::pi - zenithDir_;
			return theta;
		}
		
		/**
		 * Calculate Phi of "dir" direction
		 */
		inline double CalcDirPhi() const {
			if (!isDirCalculated_) DoCalcDir();
			double phi = I3Constants::pi + azimuthDir_;
			if (phi >= 2*I3Constants::pi) phi -= 2*I3Constants::pi;
			return phi;
		}
		
		/**
		 * Provide Zenith of "right" direction
		 */
		inline double GetRightZenith() const {
			if (!isRightCalculated_) DoCalcRight();
			return zenithRight_;
		}
		
		/**
		 * Provide Azimuth of "right" direction
		 */
		inline double GetRightAzimuth() const {
			if (!isRightCalculated_) DoCalcRight();
			return azimuthRight_;
		}
		
		/**
		 * Provide X of "right" direction in cartesian ref frame
		 */
		inline double GetRightX() const {
			if (!isRightCalculated_) DoCalcRight();
			return xRight_;
		}
		
		/**
		 * Provide Y of "right" direction in cartesian ref frame
		 */
		inline double GetRightY() const {
			if (!isRightCalculated_) DoCalcRight();
			return yRight_;
		}
		
		/**
		 * Provide Z of "right" direction in cartesian ref frame
		 */
		inline double GetRightZ() const {
			if (!isRightCalculated_) DoCalcRight();
			return zRight_;
		}
		
		/**
		 * Calculate "right" direction
		 */
		inline I3Direction GetRight() const {
			if (!isRightCalculated_) DoCalcRight();
			return I3Direction(zenithRight_, azimuthRight_);
		}
		
		/**
		 * Calculate Theta of "right" direction
		 */
		inline double CalcRightTheta() const {
			if (!isRightCalculated_) DoCalcRight();
			double theta = I3Constants::pi - zenithRight_;
			return theta;
		}
		
		/**
		 * Calculate Phi of "right" direction
		 */
		inline double CalcRightPhi() const {
			if (!isRightCalculated_) DoCalcRight();
			double phi = I3Constants::pi + azimuthRight_;
			if (phi >= 2*I3Constants::pi) phi -= 2*I3Constants::pi;
			return phi;
		}
		
		/**
		 * Provide Zenith of "front" direction
		 */
		inline double GetFrontZenith() const {
			if (!isFrontCalculated_) DoCalcFront();
			return zenithFront_;
		}
		
		/**
		 * Provide Azimuth of "front" direction
		 */
		inline double GetFrontAzimuth() const {
			if (!isFrontCalculated_) DoCalcFront();
			return azimuthFront_;
		}
		
		/**
		 * Provide X of "front" direction in cartesian ref frame
		 */
		inline double GetFrontX() const {
			if (!isFrontCalculated_) DoCalcFront();
			return xFront_;
		}
		
		/**
		 * Provide Y of "front" direction in cartesian ref frame
		 */
		inline double GetFrontY() const {
			if (!isFrontCalculated_) DoCalcFront();
			return yFront_;
		}
		
		/**
		 * Provide Z of "front" direction in cartesian ref frame
		 */
		inline double GetFrontZ() const {
			if (!isFrontCalculated_) DoCalcFront();
			return zFront_;
		}
		
		/**
		 * Calculate "front" direction
		 */
		inline I3Direction GetFront() const {
			if (!isFrontCalculated_) DoCalcFront();
			return I3Direction(zenithFront_, azimuthFront_);
		}
		
		/**
		 * Calculate Theta of "front" direction
		 */
		inline double CalcFrontTheta() const {
			if (!isFrontCalculated_) DoCalcFront();
			double theta = I3Constants::pi - zenithFront_;
			return theta;
		}
		
		/**
		 * Calculate Phi of "front" direction
		 */
		inline double CalcFrontPhi() const {
			if (!isFrontCalculated_) DoCalcFront();
			double phi = I3Constants::pi + azimuthFront_;
			if (phi >= 2*I3Constants::pi) phi -= 2*I3Constants::pi;
			return phi;
		}
		
		//--------------
		
		/**
		 * Rotate orientation around X axis by angle
		 */
		//void RotateX(double angle);
		
		/**
		 * Rotate orientation around Y axis by angle
		 */
		//void RotateY(double angle);
		
		/**
		 * Rotate orientation around Z axis by angle
		 */
		//void RotateZ(double angle);
		
		
	protected:
		/**
		 * the actual rotation w.r.t (0,0,1)
		 */ 
		I3Quaternion rot_;
		
		/**
		 * direction "dir" coordinates
		 */ 
		mutable double xDir_;	//!
		mutable double yDir_;	//!
		mutable double zDir_;	//!
		mutable double zenithDir_;	//!
		mutable double azimuthDir_;	//!

		/**
		 * direction "right" coordinates
		 */ 
		mutable double xRight_;	//!
		mutable double yRight_;	//!
		mutable double zRight_;	//!
		mutable double zenithRight_;	//!
		mutable double azimuthRight_;	//!

		/**
		 * direction "right" coordinates
		 */ 
		mutable double xFront_;	//!
		mutable double yFront_;	//!
		mutable double zFront_;	//!
		mutable double zenithFront_;	//!
		mutable double azimuthFront_;	//!
		
		/**
		 * Did we calculate the directions before?
		 */
		mutable bool isDirCalculated_;	//!
		mutable bool isRightCalculated_;	//!
		mutable bool isFrontCalculated_;	//!
		
	private:
		/**
		 * Calculate all coordinates from the internal rotation
		 */
		void DoCalcDir() const;
		void DoCalcRight() const;
		void DoCalcFront() const;
		
		friend class boost::serialization::access;
		
		template <class Archive>
		void serialize(Archive& ar, unsigned version);
	};

//bool operator==(const I3Orientation& lhs, const I3Orientation& rhs);

I3_POINTER_TYPEDEFS(I3Orientation);
BOOST_CLASS_VERSION(I3Orientation, i3orientation_version_);

typedef I3Vector<I3Orientation> I3OrientationVect;
I3_POINTER_TYPEDEFS(I3OrientationVect);

#endif //I3ORIENTATION_H_INCLUDED
