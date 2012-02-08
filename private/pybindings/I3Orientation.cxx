//
//   Copyright (c) 2009  Claudio Kopper
//   
//
//   This file is part of IceTray.
//
//   IceTray is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 3 of the License, or
//   (at your option) any later version.
//
//   IceTray is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <vector>

#include <dataclasses/I3Orientation.h>

using namespace boost::python;

void register_I3Orientation()
{
	
	void (I3Orientation::* fromOrientation)(const I3Orientation&) = &I3Orientation::SetOrientation;
	void (I3Orientation::* fromDirection)(const I3Direction&) = &I3Orientation::SetOrientation;
	void (I3Orientation::* fromDirections)(const I3Direction&, const I3Direction&) = &I3Orientation::SetOrientation;
	void (I3Orientation::* fromDoubles)(double, double, double, double, double, double) = &I3Orientation::SetOrientation;
	
	class_<I3Orientation, bases<I3FrameObject>, boost::shared_ptr<I3Orientation> >("I3Orientation")
	//.def(init<double,double,double,int>())
	.def("SetDirection", fromOrientation)
	.def("SetDirection", fromDirection)
	.def("SetDirection", fromDirections)
	.def("SetDirection", fromDoubles)
	.def("ResetOrientation", &I3Orientation::ResetOrientation)

	.def("GetZenith", &I3Orientation::GetZenith)
	.def("GetAzimuth", &I3Orientation::GetAzimuth)
	.def("GetX", &I3Orientation::GetX)
	.def("GetY", &I3Orientation::GetY)
	.def("GetZ", &I3Orientation::GetZ)
	
	.def("GetDirZenith", &I3Orientation::GetDirZenith)
	.def("GetDirAzimuth", &I3Orientation::GetDirAzimuth)
	.def("GetDirX", &I3Orientation::GetDirX)
	.def("GetDirY", &I3Orientation::GetDirY)
	.def("GetDirZ", &I3Orientation::GetDirZ)
	.def("CalcDirTheta", &I3Orientation::CalcDirTheta)
	.def("CalcDirPhi", &I3Orientation::CalcDirPhi)
	.def("GetDir", &I3Orientation::GetDir)

	.def("GetUpZenith", &I3Orientation::GetUpZenith)
	.def("GetUpAzimuth", &I3Orientation::GetUpAzimuth)
	.def("GetUpX", &I3Orientation::GetUpX)
	.def("GetUpY", &I3Orientation::GetUpY)
	.def("GetUpZ", &I3Orientation::GetUpZ)
	.def("CalcUpTheta", &I3Orientation::CalcUpTheta)
	.def("CalcUpPhi", &I3Orientation::CalcUpPhi)
	.def("GetUp", &I3Orientation::GetUp)

	.def("GetRightZenith", &I3Orientation::GetRightZenith)
	.def("GetRightAzimuth", &I3Orientation::GetRightAzimuth)
	.def("GetRightX", &I3Orientation::GetRightX)
	.def("GetRightY", &I3Orientation::GetRightY)
	.def("GetRightZ", &I3Orientation::GetRightZ)
	.def("CalcRightTheta", &I3Orientation::CalcRightTheta)
	.def("CalcRightPhi", &I3Orientation::CalcRightPhi)
	.def("GetRight", &I3Orientation::GetRight)
	;
	register_pointer_conversions<I3Orientation>();
}
