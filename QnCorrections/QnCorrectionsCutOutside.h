#ifndef QNCORRECTIONS_CUT_OUTSIDE_H
#define QNCORRECTIONS_CUT_OUTSIDE_H

/***************************************************************************
 * Package:       FlowVectorCorrections                                    *
 * Authors:       Jaap Onderwaater, GSI, jacobus.onderwaater@cern.ch       *
 *                Ilya Selyuzhenkov, GSI, ilya.selyuzhenkov@gmail.com      *
 *                Víctor González, UCM, victor.gonzalez@cern.ch            *
 *                Contributors are mentioned in the code where appropriate.*
 * Development:   2012-2016                                                *
 * See cxx source for GPL licence et. al.                                  *
 ***************************************************************************/

#include "QnCorrectionsCutsBase.h"

/// \file QnCorrectionsCutOutside.h
/// \brief Outside range cut class support for the Q vector correction framework

/// \class QnCorrectionsCutOutside
/// \brief Outside range cut class for Q vector correction
///
/// Provides support for cuts based in being outside a range
/// defined by a minimum value and a maximum value
///
/// Stores the threshold values and pass the var Id to its parent.
/// Implements IsSelected accordingly.
///
/// \author Jaap Onderwaater <jacobus.onderwaater@cern.ch>, GSI
/// \author Ilya Selyuzhenkov <ilya.selyuzhenkov@gmail.com>, GSI
/// \author Víctor González <victor.gonzalez@cern.ch>, UCM
/// \date Jan 22, 2016
class QnCorrectionsCutOutside: public QnCorrectionsCutsBase {

 public:
  QnCorrectionsCutOutside();
  QnCorrectionsCutOutside(const QnCorrectionsCutOutside &cut);
  QnCorrectionsCutOutside(Int_t varId, Float_t min, Float_t max);
  virtual ~QnCorrectionsCutOutside();

  virtual Bool_t IsSelected(const Float_t *variableContainer);
 private:
  Float_t         fMinThreshold;   ///< The lower limit
  Float_t         fMaxThreshold;   ///< The upper limit

/// \cond CLASSIMP
  ClassDef(QnCorrectionsCutOutside, 1);
/// \endcond
};

/// Check if the actual variable value passes the cut
///
/// \param variableContainer the current variables content addressed by var Id
/// \return kTRUE if the actual value is below the threshold else kFALSE
inline Bool_t QnCorrectionsCutOutside::IsSelected(const Float_t *variableContainer) {
  if ((fMinThreshold < variableContainer[fVarId]) && (variableContainer[fVarId] < fMaxThreshold))
    return kFALSE;
  else
    return kTRUE;
}

#endif // QNCORRECTIONS_CUT_OUTSIDE_H
