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
- Should have 4 areas with specific responsibility:
    1. Working directory: current working directory
    2. Upstream repository: destination of git push/pull/fetch
    3. Staging area: files that being added by "git add" but not commited yet
    4. Local repository: files that are committed and waiting to be pushed to upstream
- Flow: git add -> add changed file to staging area -> git commit -> update local repository -> git push -> push to upstream repo

          ┌────────────────────┐
          │   Upstream Area    │
          │ (Remote Repository)│
          └─────────▲──────────┘
                    │
                git push
                    │
                    ▼
          ┌────────────────────┐
          │  Downstream Area   │
          │ (Local Repository) │
          │   - committed,     │
          │     not yet pushed │
          └─────────▲──────────┘
                    │
                git commit
                    │
                    ▼
          ┌────────────────────┐
          │   Staged Area      │
          │ (Index / Cache)    │
          │ - added by "git add"│
          └─────────▲──────────┘
                    │
                git add
                    │
                    ▼
          ┌────────────────────┐
          │    Local Area      │
          │ (Working Directory)│
          │ - edited files     │
          └────────────────────┘

Pull flow:
Upstream ──(git fetch/pull)──▶ Downstream ──(merge)──▶ Local


# Error history
- clang: error: linker command failed with exit code 1, Undefined symbols for architecture arm64 -> missing .cpp file
in the file list of g++/clang
