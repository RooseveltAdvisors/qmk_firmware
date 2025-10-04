# QMK Keymap Debugging Session Insights

## Session Summary
Fixed layer 0 mapping issues in Piantor Pro voyager_adapted keymap where characters were cross-mapped incorrectly.

## Key Technical Insights

### Problem Pattern
- **Root Cause**: Mismatch between physical key positions and `process_record_user` function outputs
- **Symptom**: Z outputting X, X outputting C, wrong symbol mappings
- **Detection**: User reported specific character mapping errors

### Solution Approach
1. **Cross-reference Original**: Always check original Voyager keymap for correct behaviors
2. **Physical Position Mapping**: Ensure DUAL_FUNC definitions match physical key positions
3. **process_record_user Alignment**: Verify each case outputs correct character for its position
4. **Compilation Validation**: Test build after each major change

### QMK-Specific Learnings
- **LAYOUT Macro Validation**: LAYOUT_split_3x6_3 requires exact 42 arguments
- **Dual Function Keys**: Use `process_record_user` to override LT() behavior when needed
- **Key Position Verification**: Physical layout must match logical DUAL_FUNC assignments

## User Preferences Captured
- **Git Commits**: No Claude Code attribution (stored in git_commit_preferences memory)
- **Technical Focus**: Prefers direct technical solutions over explanatory content

## Debugging Methodology
1. Read original source (Voyager keymap) for ground truth
2. Compare current implementation against original
3. Identify specific mismatches in process_record_user
4. Fix mappings systematically
5. Compile test after each change
6. Verify final behavior matches requirements

## Quality Standards Applied
- Compilation must succeed
- Maintain QMK coding conventions
- Cross-reference original designs
- Apply user-specific preferences
- Document changes appropriately

## Session Outcome
✅ All layer 0 mapping issues resolved
✅ Keymap compiles successfully
✅ User preferences applied to commit
✅ Technical insights documented for future sessions