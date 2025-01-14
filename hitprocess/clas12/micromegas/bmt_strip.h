#ifndef bmt_strip_H
#define bmt_strip_H 1


#include <vector>
using namespace std;

/// \class bmt_strip
/// <b> bmt_strip </b>\n\n
/// Micromegas strip finding routine\n


class bmt_strip
{
	public:

		// THE GEOMETRY CONSTANTS
		const static int NREGIONS = 3  ;	// 3 regions of MM
		
		//Z detector characteristics
		double CRZRADIUS[NREGIONS] ; 		// the radius of the Z detector in mm
		int CRZNSTRIPS[NREGIONS] ; 			// the number of strips
		double CRZSPACING[NREGIONS] ; 		// the strip spacing in mm
		double CRZWIDTH[NREGIONS] ; 		// the strip width in mm
		double CRZLENGTH[NREGIONS] ; 		// the strip length in mm
		double CRZZMIN[NREGIONS] ; 			// PCB upstream extremity mm
		double CRZZMAX[NREGIONS] ; 			// PCB downstream extremity mm
		double CRZOFFSET[NREGIONS] ; 		// Beginning of strips in mm
		vector<vector<double> >  CRZEDGE1; 	// the angle of the first edge of each PCB detector A, B, C
		vector<vector<double> >  CRZEDGE2; 	// the angle of the second edge of each PCB detector A, B, C
		double CRZXPOS[NREGIONS]; 			// Distance on the PCB between the PCB first edge and the edge of the first strip in mm

		//C detector characteristics
		double CRCRADIUS[NREGIONS]; 		// the radius of the Z detector in mm
		int CRCNSTRIPS[NREGIONS]; 			// the number of strips
		double CRCSPACING[NREGIONS]; 		// the strip spacing in mm
		double CRCLENGTH[NREGIONS]; 		// the strip length in mm
		double CRCZMIN[NREGIONS]; 			// PCB upstream extremity mm
		double CRCZMAX[NREGIONS]; 			// PCB downstream extremity mm
		double CRCOFFSET[NREGIONS]; 		// Beginning of strips in mm
		vector<vector<int> >  CRCGROUP; 	// Number of strips with same width
		vector<vector<double> >  CRCWIDTH;	// the width of the corresponding group of strips
		vector<vector<double> >  CRCEDGE1; 	// the angle of the first edge of each PCB detector A, B, C
		vector<vector<double> >  CRCEDGE2; 	// the angle of the second edge of each PCB detector A, B, C
		double CRCXPOS[NREGIONS]; 			// Distance on the PCB between the PCB first edge and the edge of the first strip in mm

		// THE SIMULATION CONSTANTS
		double Pi ;
		double SigmaDrift;					// Max transverse diffusion value (GEMC value)
		double hDrift;						// Size of the drift gap
		double hStrip2Det;					// distance between strips and the middle of the conversion gap (~half the drift gap)
		double ThetaL ;						// the Lorentz angle
		int FieldFlag ; 					// A flag to indicate if the field is on; if value = 0, then the field is off, if value = 1, the field is 5-T

		void fill_infos(); 
		vector<double> FindStrip( int layer, int sector, double x, double y, double z, double Edep);   // Strip Finding Routine
		double toRadians(double angleDegrees);
		double getSigmaAzimuth(int layer, double x, double y); 					// sigma for Z-detectors
		double getSigmaLongit(int layer, double x, double y);  					// sigma for C-detector
		int getZStrip(int layer, double angle); 								// the Z strip as a function of azimuthal angle
		int getCStrip(int layer, double trk_z); 								// the Z strip as a function of z
		double CRCStrip_GetZ(int layer, int strip); 							// the z position of a given C strip
		double CRZStrip_GetPhi(int sector, int layer, int strip);				// the phi angle of a given Z strip
		double getEnergyFraction(double z0, double z, double sigma); 			// gaussian pdf
		int getDetectorIndex(int sector);										// index of the detector (0...2): sector 1 corresponds to detector B, 2 to A,  3 to C in the geometry created by GEMC
		int isInSector(int layer, double angle);							    // the sector according to this geometry defined in fillinfos()
};

#endif
