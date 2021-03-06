#ifndef QNCORRECTIONS_CORRECTIONSETONQNVECTOR_H
#define QNCORRECTIONS_CORRECTIONSETONQNVECTOR_H

/***************************************************************************
 * Package:       FlowVectorCorrections                                    *
 * Authors:       Jaap Onderwaater, GSI, jacobus.onderwaater@cern.ch       *
 *                Ilya Selyuzhenkov, GSI, ilya.selyuzhenkov@gmail.com      *
 *                Víctor González, UCM, victor.gonzalez@cern.ch            *
 *                Contributors are mentioned in the code where appropriate.*
 * Development:   2012-2016                                                *
 * See cxx source for GPL licence et. al.                                  *
 ***************************************************************************/

/// \file QnCorrectionsCorrectionsSetOnQvector.h
/// \brief Set of corrections on Qn vector support within Q vector correction framework
///

#include <TNamed.h>
#include <TList.h>

#include "QnCorrectionsCorrectionStepBase.h"
#include "QnCorrectionsCorrectionOnQvector.h"

/// \class QnCorrectionsCorrectionsSetOnQvector
/// \brief Encapsulate the set of corrections to apply on Q vectors
///
/// Order matters so, the list must be built with the order in which
/// corrections should be applied.
///
/// The correction steps are own by the object instance so they will
/// be destroyed with it.
///
/// \author Jaap Onderwaater <jacobus.onderwaater@cern.ch>, GSI
/// \author Ilya Selyuzhenkov <ilya.selyuzhenkov@gmail.com>, GSI
/// \author Víctor González <victor.gonzalez@cern.ch>, UCM
/// \date Feb 05, 2016

class QnCorrectionsCorrectionsSetOnQvector: public TList {
public:
  QnCorrectionsCorrectionsSetOnQvector();
  virtual ~QnCorrectionsCorrectionsSetOnQvector();

  /// Access the correction step at the passed position
  /// \param i position in the list (starting at zero)
  /// \return the correction step object a position i
  virtual QnCorrectionsCorrectionOnQvector *At(Int_t i) const
    { return (QnCorrectionsCorrectionOnQvector *) TList::At(i);}

  void AddCorrection(QnCorrectionsCorrectionOnQvector *correction);
  void FillOverallCorrectionsList(TList *correctionlist) const;
  const QnCorrectionsCorrectionOnQvector *GetPrevious(const QnCorrectionsCorrectionOnQvector *correction) const;
  Bool_t IsCorrectionStepBeingApplied(const char *name) const;
/// \cond CLASSIMP
  ClassDef(QnCorrectionsCorrectionsSetOnQvector, 1);
/// \endcond
};

#endif // QNCORRECTIONS_CORRECTIONSETONQNVECTOR_H
