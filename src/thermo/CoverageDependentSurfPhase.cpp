/**
 *  @file CoverageDependentSurfPhase.cpp
 *  Definitions for a simple thermodynamic model of a coverage-dependent 
 *  surface phase derived from SurfPhase, assuming an ideal solution model
 *  (see \ref thermoprops and class
 *  \link Cantera::CoverageDependentSurfPhase CoverageDependentSurfPhase\endlink).
 */

// This file is part of Cantera. See License.txt in the top-level directory or
// at https://cantera.org/license.txt for license and copyright information.

#include "cantera/thermo/CoverageDependentSurfPhase.h"

using namespace std;

namespace Cantera
{
CoverageDependentSurfPhase::CoverageDependentSurfPhase(doublereal n0):
    m_press(OneAtm)
{
    setSiteDensity(n0);
    setNDim(2);
}

CoverageDependentSurfPhase::CoverageDependentSurfPhase(const std::string& infile, const std::string& id_):
    m_press(OneAtm)
{
    initThermoFile(infile, id_);
}

CoverageDependentSurfPhase::CoverageDependentSurfPhase(XML_Node& xmlphase):
    m_press(OneAtm)
{
    importPhase(xmlphase, this);
}

doublereal CoverageDependentSurfPhase::enthalpy_mole() const
{
    if (m_n0 <= 0.0) {
        return 0.0;
    }
    _updateThermo();
    return mean_X(m_h0);
}

/*!
doublereal CoverageDependentSurfPhase::entropy_mole() const
{

}

doublereal CoverageDependentSurfPhase::cp_mole() const
{

}

void CoverageDependentSurfPhase::getChemPotentials(doublereal* mu) const
{

}
void CoverageDependentSurfPhase::getPartialMolarEnthalpies(doublereal* hbar) const
{

}
void CoverageDependentSurfPhase::getPartialMolarEntropies(doublereal* sbar) const
{

}
void CoverageDependentSurfPhase::getPartialMolarCp(doublereal* cpbar) const
{

}

void CoverageDependentSurfPhase::getStandardChemPotentials(doublereal* mu0) const
{

}

void CoverageDependentSurfPhase::getGibbs_RT(doublereal* grt) const
{

}
void CoverageDependentSurfPhase::getEnthalpy_RT(doublereal* hrt) const
{

}
void CoverageDependentSurfPhase::getEntropy_R(doublereal* sr) const
{

}
void CoverageDependentSurfPhase::getCp_R(doublereal* cpr) const
{

}
*/


void CoverageDependentSurfPhase::_updateThermo(bool force) const
{
    doublereal tnow = temperature();
    doublereal covnow = coverage();
    if (m_tlast != tnow || m_covlast != covnow || force) {
        m_spthermo.update(tnow, m_cp0.data(), m_h0.data(), m_s0.data());
        m_tlast = tnow;
        m_covlast = covnow;
        for (size_t k = 0; k < m_kk; k++) {
            m_h0[k] *= GasConstant * tnow;
            m_s0[k] *= GasConstant;
            m_cp0[k] *= GasConstant;
            m_mu0[k] = m_h0[k] - tnow*m_s0[k];
        }
        m_tlast = tnow;
    }
}


}