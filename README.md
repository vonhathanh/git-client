# git-client
CLI app to interact with git-server

# requirements
This is just a minimal version of git, supported commands are:
- push
- pull
- fetch
- merge
- rebase
- squash commits
- cherry-pick
- reset
- revert
- checkout
- clone
- diff
- add

# design

## 1. repository
- Should have 3 areas for:
    1. Local repo
    2. Upstream repo
    3. Temp repo
    4. Staged repo
- Flow: git add -> add changed file to temp repo -> git commit -> update staged repo -> git push -> push to upstream repo
- 