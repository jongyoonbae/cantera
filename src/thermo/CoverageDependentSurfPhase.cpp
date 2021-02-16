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

doublereal CoverageDependentSurfPhase::entropy_mole() const
{
    return 1234.5678;
}

/*!
*void CoverageDependentSurfPhase::_updateThermo(bool force) const
*{
*    doublereal tnow = temperature();
*    doublereal covnow = coverage();
*    if (m_tlast != tnow || m_covlast != covnow || force) {
*        m_spthermo.update(tnow, m_cp0.data(), m_h0.data(), m_s0.data());
*        m_tlast = tnow;
*        m_covlast = covnow;
*        for (size_t k = 0; k < m_kk; k++) {
*            m_h0[k] *= GasConstant * tnow;
*            m_s0[k] *= GasConstant;
*            m_cp0[k] *= GasConstant;
*            m_mu0[k] = m_h0[k] - tnow*m_s0[k];
*        }
*        m_tlast = tnow;
*    }
*}
*/

}