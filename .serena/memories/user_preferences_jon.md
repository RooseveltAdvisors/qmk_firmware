# User Preferences - Jon

## User Profile

### Typing Characteristics
- **Average WPM**: 74 words per minute
- **Typing Style**: Fast typing with quick same-hand rolls
- **Primary Editor**: Vim (Ctrl+C quit command is critical)
- **Keyboard**: Piantor Pro with 20gf light switches (Kailh Choc low-profile)

## Communication Style

### Preferred Approach
- **Direct and technical** - skip preamble, get to the point
- **Evidence-based** - show code, explain reasoning, avoid speculation
- **Concise responses** - brief confirmations after completing work
- **No marketing language** - avoid superlatives, enthusiasm, or sales-like tone

### Teaching Style
- **Socratic method** - guides through questions rather than demanding answers
- **Demands understanding** - "don't make beginner mistakes" means comprehend before implementing
- **Pattern recognition** - encourages finding patterns in existing code
- **Consistency over cleverness** - values following established patterns

### Feedback Style
- **Stops incorrect approaches** - intervenes when seeing wrong direction
- **Asks critical questions** - reveals deeper issues through questioning
- **Confirms functionality** - tests and reports back on what works/doesn't work
- **Requests reflection** - asks for learning documentation before moving forward

## Development Workflow

### Git Commits
- **No AI attribution** - Never include "Generated with Claude Code" or similar
- **Descriptive commit messages** - Clear problem/solution format
- **Functional commits** - Commit when functionality is working
- **Safety commits** - Commit before risky changes to enable rollback

### Code Changes
- **Understand first, implement second** - mandatory pattern
- **Comprehensive planning** - wants full plan before execution for complex changes
- **Read existing code** - study patterns before deviating
- **Test after changes** - immediate feedback on functionality

### Quality Standards
- **Consistency with codebase** - follow existing patterns religiously
- **Working is not enough** - code must also be consistent and maintainable
- **Question differences** - "Why are you doing X differently than Y?"
- **Functional correctness** - must work as specified, no partial implementations

## Technical Preferences

### QMK Firmware
- **Light switches** - Uses 20gf switches on Piantor Pro
- **Timing sensitivity** - Tap/hold behavior must be precise for light switches
- **Over-trigger prevention** - Critical for sensitive commands (Ctrl+C, Ctrl+A)
- **Vim usage** - Ctrl+C is quit in Vim, must not over-trigger

### Keyboard Layouts
- **Piantor Pro** - Primary keyboard (42 keys, 3x6 layout + 3 thumbs per side)
- **Voyager** - Reference implementation (52 keys, 4x6 layout + 2 thumbs per side)
- **Adaptation pattern** - Piantor Pro adapted from Voyager with layout differences

### Flash Workflow
- **Command preference** - "flash to Piantor Pro" means compile + copy UF2 to RPI-RP2 volume
- **Not using qmk flash** - Manual bootloader mode + file copy workflow
- **Memory stored** - See piantor_pro_flash_workflow.md

## Session Management

### Reflection Practice
- **Requests reflection** - "please summarize all your learning and findings"
- **Documents lessons learned** - wants comprehensive documentation for future reference
- **Captures preferences** - asks to update memory with user preferences
- **Cross-session learning** - values persistent learning across sessions
- **Memory consolidation** - prefers consolidated comprehensive guides over scattered notes

### Problem-Solving Approach
- **Iterative refinement** - willing to try multiple approaches
- **Fast feedback loops** - tests immediately and reports results
- **Stops bad patterns** - intervenes when seeing incorrect direction
- **Teaches through failure** - uses failed attempts as learning opportunities

## Critical Insights

### The Consistency Question
User's most valuable contribution: "Why are you programming single quote differently than comma, semicolon, Z and X?"

**What this revealed:**
- User understands codebase patterns deeply
- User values consistency over technical novelty
- Working code is necessary but not sufficient
- Different approaches require justification, not just functionality

### The Over-Trigger Clarification
Initial misunderstanding: "over-trigger" could mean accidental holds or timing issues
User clarification: "if I keep pressing C or V, you should not send multiple Ctrl C and Ctrl V signal"

**What this taught:**
- User describes behavior in functional terms, not technical terms
- Clarifying questions are essential for understanding requirements
- Key repeat is the specific mechanism that needed addressing
- Vim usage context made the requirement critical (Ctrl+C quits)

### The PERMISSIVE_HOLD Discovery
User reported: "If I type CHANGE really quickly, it deletes everything and outputs ANG"

**What this revealed:**
- At 74 WPM, overlapping key presses are common (~150-160ms between keys)
- `PERMISSIVE_HOLD` interprets C-H overlap as "hold C" → triggers Ctrl+C
- Fast typing patterns are incompatible with `PERMISSIVE_HOLD`
- Configuration must account for actual typing speed, not just theory

### The Guidance Pattern
1. **Stops premature implementation** - "wait, don't make beginner mistakes"
2. **Demands comprehensive analysis** - "read through codebase, come up with a plan"
3. **Approves plans** - "okay, please go ahead and implement option A"
4. **Tests and reports** - "everything worked as it should"
5. **Questions approach** - "why are you doing X differently?"
6. **Requests reflection** - "summarize all your learning"

## Memory Management Preferences

### Documentation Style
- **Consolidated guides** - prefers comprehensive single documents over scattered notes
- **Markdown format** - wants summaries in markdown format
- **Memory persistence** - values cross-session learning storage
- **Comprehensive coverage** - prefers thorough documentation over brief notes
- **Future reference focus** - documents for future sessions, not just current

### Memory Organization
- **Periodic consolidation** - "time to consolidate your memory files, there are too many"
- **Quality over quantity** - better to have fewer comprehensive guides than many fragments
- **Practical focus** - documentation should support future development work

## Interaction Quality Markers

### What Jon Appreciates
✅ Understanding layout differences (Voyager vs Piantor Pro)
✅ Comprehensive planning before implementation
✅ Following established codebase patterns
✅ Functional correctness with no over-triggering
✅ Learning documentation and reflection
✅ Asking clarifying questions when unclear
✅ Consolidated comprehensive memory files

### What Jon Corrects
❌ Making changes without understanding
❌ Beginner mistakes (not studying existing patterns)
❌ Inconsistency with codebase conventions
❌ Implementing without comprehensive planning
❌ Missing critical edge cases (over-trigger)
❌ Too many fragmented memory files

## Session Excellence Example

### PERMISSIVE_HOLD Fix Session
1. User reported specific functional issue: "CHANGE" → deletes text, outputs "ANG"
2. I identified root cause: `PERMISSIVE_HOLD` + 74 WPM fast typing
3. Removed `PERMISSIVE_HOLD`, added `QUICK_TAP_TERM 120`
4. Increased `TAPPING_TERM` to 250ms for more conservative behavior
5. Compiled and flashed successfully
6. User confirmed fix works correctly
7. User requested reflection and memory consolidation
8. Consolidated 7 fragmented memories into comprehensive guide

**Key characteristics of excellent session:**
- Fast problem identification (user typing speed was key insight)
- Root cause analysis (PERMISSIVE_HOLD incompatible with fast typing)
- Clean implementation (removed problematic feature, added protective feature)
- Immediate testing and validation
- Comprehensive documentation with memory consolidation

**User feedback**: "You did great work. I mean it's getting very close to my perfect preference"

## Key Takeaways

### Technical Excellence
- Document user's WPM (74) for future timing configuration
- Account for typing speed in all tap-hold configurations
- Light switches (20gf) need special timing considerations
- Over-trigger protection critical for Vim usage

### Process Excellence
- Understand first, implement second (mandatory)
- Follow existing patterns religiously
- Test immediately after changes
- Consolidate learnings into comprehensive guides

### Communication Excellence
- Direct and technical communication
- Evidence-based reasoning
- Concise confirmations
- Memory consolidation when requested