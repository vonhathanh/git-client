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

## 1. commit workflow
Should have 4 areas with specific responsibility:
    1. Working directory: current working directory
    2. Upstream repository: destination of git push/pull/fetch
    3. Staging area: files that being added by "git add" but not commited yet
    4. Local repository: files that are committed and waiting to be pushed to upstream
Flow: git add -> add changed file to staging area -> git commit -> update local repository -> git push -> push to upstream repo

          ┌────────────────────┐
          │   Upstream Area    │
          │ (Remote Repository)│
          └─────────▲──────────┘
                    │
                git push
                    │
          ┌────────────────────┐
          │  Downstream Area   │
          │ (Local Repository) │
          │   - committed,     │
          │     not yet pushed │
          └─────────▲──────────┘
                    │
                git commit
                    │
          ┌────────────────────┐
          │   Staged Area      │
          │ (Index / Cache)    │
          │ - added by "git add"│
          └─────────▲──────────┘
                    │
                git add
                    │
          ┌────────────────────┐
          │    Local Area      │
          │ (Working Directory)│
          │ - edited files     │
          └────────────────────┘

Pull flow:
Upstream ──(git fetch/pull)──▶ Downstream ──(merge)──▶ Local

## 2. repository structure
.git folder
    - index file
    - commits folder
    - refs folder: contains all branches

## 2.1 index file content
- branch name
- head commit
- file_1: commit hash, file size, md5 hash, last updated time
...
- file_n: commit hash, file size, md5 hash, dsddslast updated time

## 2.2 commits folder
Each child folder is named by commit hash
Each folder contains file that changed by that commit

## 3. git branches
Where do we store branches, so "git branch" can list all branches?
-> refs folders: contains all branches -> what is the structure of this folder?
Idea 1: Should we store all branches in an index file, like this:
    branch A: head commit
    branch B: head commit
    ...
Idea 2: Should we have a separate file for each branch, that file could be the branch's index file
    branch_A.file
    branch_B.file
    ...
-> Idea 2 is better

## 3.1 Next step: "git checkout"
If we store branches correctly, git checkout would be fast and easy
What happen when we checkout branch_X?
    - override current index file by branch_X/index
    - read index file, check if a file commit hash != index file commit has
    - override that file by file from commits/ dir

# error history
- clang: error: linker command failed with exit code 1, Undefined symbols for architecture arm64 -> missing .cpp file
in the file list of g++/clang
