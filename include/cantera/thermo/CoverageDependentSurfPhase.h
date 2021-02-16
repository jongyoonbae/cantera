/**
 *  @file CoverageDependentSurfPhase.h
 *  Header for a simple thermodynamics model of a coverage-dependent surface 
 *  phase derived from SurfPhase, assuming an ideal solution model
 *  (see \ref thermoprops and class
 *  \link Cantera::CoverageDependentSurfPhase CoverageDependentSurfPhase\endlink).
 */

// This file is part of Cantera. See License.txt in the top-level directory or
// at https://cantera.org/license.txt for license and copyright information.

#ifndef CT_COVERAGEDEPENDENTSURFPHASE_H
#define CT_COVERAGEDEPENDENTSURFPHASE_H

#include "SurfPhase.h"

namespace Cantera
{

class CoverageDependentSurfPhase : public SurfPhase
{
public:

    virtual std::string type() const {
        return "CovDepSurf";
    }

    virtual doublereal enthalpy_mole() const;

    //intEnergy SAME as SurfPhase: intEnergy = ethalpy
    //virtual doublereal intEnergy_mole() const;

    virtual doublereal entropy_mole() const;

    virtual doublereal cp_mole() const;
    
    //cv SAME as SurfPhase: cv = cp
    //virtual doublereal cv_mole() const;

    virtual void getChemPotentials(doublereal* mu) const;
    virtual void getPartialMolarEnthalpies(doublereal* hbar) const;
    virtual void getPartialMolarEntropies(doublereal* sbar) const;
    virtual void getPartialMolarCp(doublereal* cpbar) const;
    //PartialMolarVolumes SAME as SurfPhase: MolarVolume = MolarArea
    virtual void getPartialMolarVolumes(doublereal* vbar) const;
    virtual void getStandardChemPotentials(doublereal* mu0) const;

private:
    //! Update the species reference state thermodynamic functions
    /*!
     * The polynomials for the standard state functions are only reevaluated if
     * the temperature or the COVERAGE has changed.
     *
     * @param force  Boolean, which if true, forces a reevaluation of the thermo
     *               polynomials. default = false.
     */
    void _updateThermo(bool force=false) const;
};

};

}

#endif