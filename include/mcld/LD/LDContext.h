//===- ELFDSOWriter.h -----------------------------------------------------===//
//
//                     The MCLinker Project
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// LDContext stores the real content of a file.
// It is possible that multiple libraries reference to a same file,
// this shared file will be converted into a LDContext.
//
//===----------------------------------------------------------------------===//

#ifndef MCLD_LD_LDCONTEXT_H
#define MCLD_LD_LDCONTEXT_H
#ifdef ENABLE_UNITTEST
#include <gtest.h>
#endif

#include "mcld/ADT/StringMap.h"
#include "mcld/LD/Relocation.h"
#include "mcld/Support/FileSystem.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/ADT/ilist.h"
#include "llvm/ADT/OwningPtr.h"
#include "llvm/MC/MCAssembler.h"
#include "llvm/MC/MCContext.h"
#include "llvm/MC/MCSectionELF.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/Allocator.h"
#include "llvm/Support/MemoryBuffer.h"
#include <map>
#include <utility>

using namespace llvm;

typedef llvm::StringMap<const MCSectionELF*> ELFUniqueMapTy;

namespace llvm
{
  class MCSection;
  class MCSectionData;
} // namespace of llvm

namespace mcld
{

/** \class LDContext
 *  \brief LDContext stores the data which a object file should has
 */
class LDContext
{
public:
  LDContext() {
    ELFUniquingMap = 0;
  }

  ~LDContext() {}

  typedef iplist<MCSectionData> SectionDataListType;
  typedef iplist<MCSymbolData> SymbolDataListType;

  typedef llvm::StringMap<MCSymbol*, BumpPtrAllocator&> SymbolTableType;

  typedef SectionDataListType::const_iterator const_iterator;
  typedef SectionDataListType::iterator iterator;

  typedef SymbolDataListType::const_iterator const_symbol_iterator;
  typedef SymbolDataListType::iterator symbol_iterator;

  typedef std::vector<RelocationEntry>::const_iterator const_reloc_iterator;
  typedef std::vector<RelocationEntry>::iterator reloc_iterator;

  //Section List Access
  SectionDataListType Sections;
  SymbolDataListType Symbols;
  RelocationInfo m_Reloc;

  const SectionDataListType &getSectionList() const { return Sections; }
  SectionDataListType &getSectionList() { return Sections; }

  iterator begin() { return Sections.begin(); }
  const_iterator begin() const { return Sections.begin(); }

  iterator end() { return Sections.end(); }
  const_iterator end() const { return Sections.end(); }

  size_t size() const { return Sections.size(); }

  //Symbol List Access
  const SymbolDataListType &getSymbolList() const { return Symbols; }
  SymbolDataListType &getSymbolList() { return Symbols; }

  symbol_iterator symbol_begin() { return Symbols.begin(); }
  const_symbol_iterator symbol_begin() const { return Symbols.begin(); }

  symbol_iterator symbol_end() { return Symbols.end(); }
  const_symbol_iterator symbol_end() const { return Symbols.end(); }

  // Relocation sequential access
  reloc_iterator reloc_begin() { return m_Reloc.entries.begin(); }
  const_reloc_iterator reloc_begin() const { return m_Reloc.entries.begin(); }
  reloc_iterator reloc_end() { return m_Reloc.entries.end(); }
  const_reloc_iterator reloc_end() const { return m_Reloc.entries.end(); }


  // FIXME: Avoid this indirection?
  DenseMap<const MCSection*, MCSectionData*> SectionMap;

  // FIXME: Avoid this indirection?
  DenseMap<const MCSymbol*,MCSymbolData*> SymbolMap;

  void *ELFUniquingMap;

public:
  RelocationInfo& getRelocInfo() { return m_Reloc; }
  const RelocationInfo& getRelocInfo() const { return m_Reloc; }
};


} // namespace of mcld

#endif


>>>>>>> Move MC/MCLDContext to LD/LDContext.
