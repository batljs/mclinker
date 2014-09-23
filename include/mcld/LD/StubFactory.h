//===- StubFactory.h ------------------------------------------------------===//
//
//                     The MCLinker Project
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef MCLD_LD_STUBFACTORY_H
#define MCLD_LD_STUBFACTORY_H

#include <llvm/Support/DataTypes.h>

#include <vector>

namespace mcld {

class BranchIslandFactory;
class IRBuilder;
class Relocation;
class Stub;

/** \class StubFactory
 *  \brief the clone factory of Stub
 *
 */
class StubFactory
{
public:
  ~StubFactory();

  /// addPrototype - register a stub prototype
  void addPrototype(Stub* pPrototype);

  /// create - create a stub if needed, otherwise return NULL
  Stub* create(Relocation& pReloc,
               uint64_t pTargetSymValue,
               IRBuilder& pBuilder,
               BranchIslandFactory& pBRIslandFactory);

private:
  /// findPrototype - find if there is a registered stub prototype for the given
  ///                 relocation
  Stub* findPrototype(const Relocation& pReloc,
                      const uint64_t pSource,
                      uint64_t pTargetSymValue);

private:
 typedef std::vector<Stub*> StubPoolType;

private:
  StubPoolType m_StubPool; // stub pool
};

} // namespace mcld

#endif
