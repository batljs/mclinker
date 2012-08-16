//===- ELFMCLinker.h ------------------------------------------------------===//
//
//                     The MCLinker Project
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// ELFMCLinker is a customized linker pass for ELF platform.
// This pass set up default parameters for ELF.
//
//===----------------------------------------------------------------------===//
#ifndef MCLD_ELF_SECTION_LINKER_H
#define MCLD_ELF_SECTION_LINKER_H
#ifdef ENABLE_UNITTEST
#include <gtest.h>
#endif
#include <mcld/CodeGen/MCLinker.h>

namespace mcld
{

class ELFMCLinker : public MCLinker
{
public:
  ELFMCLinker(SectLinkerOption &pOption, mcld::TargetLDBackend &pLDBackend);

  virtual ~ELFMCLinker();
};

} // namespace of mcld

#endif
