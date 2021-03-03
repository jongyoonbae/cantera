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
    
    //SAME
    //virtual void getPartialMolarVolumes(doublereal* vbar) const;
    
    virtual void getStandardChemPotentials(doublereal* mu0) const;

    //SAME
    //virtual void getActivityConcentrations(doublereal* c) const;
    //virtual doublereal standardConcentration(size_t k = 0) const;
    //virtual doublereal logStandardConc(size_t k=0) const;
    //virtual void setParameters(int n, doublereal* const c);
    //virtual void setParametersFromXML(const XML_Node& thermoData);

    //SAME
    //virtual void initThermo();
    //virtual bool addSpecies(shared_ptr<Species> spec);
    //virtual void setStateFromXML(const XML_Node& state);
    //virtual void setState(const AnyMap& state);
    //doublereal siteDensity()
    //virtual double size(size_t k) const
    //void setSiteDensity(doublereal n0);

    virtual void getGibbs_RT(doublereal* grt) const;
    virtual void getEnthalpy_RT(doublereal* hrt) const;
    virtual void getEntropy_R(doublereal* sr) const;
    virtual void getCp_R(doublereal* cpr) const;

    //SAME
    //virtual void getStandardVolumes(doublereal* vol) const;
    //virtual doublereal pressure() const
    //virtual void setPressure(doublereal p)

    //SAME thermodynamic properties at the standard state
    //virtual void getPureGibbs(doublereal* g) const;
    //virtual void getGibbs_RT_ref(doublereal* grt) const;
    //virtual void getEnthalpy_RT_ref(doublereal* hrt) const;
    //virtual void getEntropy_R_ref(doublereal* er) const;
    //virtual void getCp_R_ref(doublereal* cprt) const;

    //SAME
    //void setCoverages(const doublereal* theta);
    //void setCoveragesNoNorm(const doublereal* theta);
    //void setCoveragesByName(const std::string& cov);
    //void setCoveragesByName(const compositionMap& cov);
    
    //SAME
    //void getCoverages(doublereal* theta) const;
    
protected:
    //! Surface site density (kmol m-2)
    doublereal m_n0;

    //! Vector of species sizes (number of sites occupied). length m_kk.
    vector_fp m_speciesSize;

    //! log of the surface site density
    doublereal m_logn0;

    //! Current value of the pressure (Pa)
    doublereal m_press;

    //! Temporary storage for the reference state enthalpies
    mutable vector_fp m_h0;

    //! Temporary storage for the reference state entropies
    mutable vector_fp m_s0;

    //! Temporary storage for the reference state heat capacities
    mutable vector_fp m_cp0;

    //! Temporary storage for the reference state Gibbs energies
    mutable vector_fp m_mu0;

    //! Temporary work array
    mutable vector_fp m_work;

    //! vector storing the log of the size of each species.
    /*!
     * The size of each species is defined as the number of surface sites each
     * species occupies.
     */
    mutable vector_fp m_logsize;

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