# This file is configured by CMake automatically as DartConfiguration.tcl
# If you choose not to use CMake, this file may be hand configured, by
# filling in the required variables.


# Configuration directories and files
SourceDirectory: /home/zhaomr/workdir/cepc/Tracking/000test
BuildDirectory: /home/zhaomr/workdir/cepc/Tracking/000test/build

# Where to place the cost data store
CostDataFile: 

# Site is something like machine.domain, i.e. pragmatic.crd
Site: hepfarm20

# Build name is osname-revision-compiler, i.e. Linux-2.4.2-2smp-c++
BuildName: Linux-c++

# Submission information
IsCDash: 
CDashVersion: 
QueryCDashVersion: 
DropSite: 
DropLocation: 
DropSiteUser: 
DropSitePassword: 
DropSiteMode: 
DropMethod: http
TriggerSite: 
ScpCommand: /projects/ilc/soft/v01-17-06/mysql/usr/bin/scp

# Dashboard start time
NightlyStartTime: 00:00:00 EDT

# Commands for the build/test/submit cycle
ConfigureCommand: "/projects/ilc/soft/v01-17-06/CMake/2.8.5/bin/cmake" "/home/zhaomr/workdir/cepc/Tracking/000test"
MakeCommand: /projects/ilc/soft/v01-17-06/mysql/usr/bin/gmake -i
DefaultCTestConfigurationType: Release

# CVS options
# Default is "-d -P -A"
CVSCommand: /projects/ilc/soft/v01-17-06/mysql/usr/bin/cvs
CVSUpdateOptions: -d -A -P

# Subversion options
SVNCommand: /projects/ilc/soft/v01-17-06/mysql/usr/bin/svn
SVNUpdateOptions: 

# Git options
GITCommand: /projects/ilc/soft/v01-17-06/mysql/usr/bin/git
GITUpdateOptions: 
GITUpdateCustom: 

# Generic update command
UpdateCommand: /projects/ilc/soft/v01-17-06/mysql/usr/bin/svn
UpdateOptions: 
UpdateType: svn

# Compiler info
Compiler: /projects/ilc/soft/v01-17-06/mysql/usr/bin/c++

# Dynamic analysis and coverage
PurifyCommand: 
ValgrindCommand: 
ValgrindCommandOptions: 
MemoryCheckCommand: /projects/ilc/soft/v01-17-06/mysql/usr/bin/valgrind
MemoryCheckCommandOptions: 
MemoryCheckSuppressionFile: 
CoverageCommand: /projects/ilc/soft/v01-17-06/mysql/usr/bin/gcov

# Cluster commands
SlurmBatchCommand: SLURM_SBATCH_COMMAND-NOTFOUND
SlurmRunCommand: SLURM_SRUN_COMMAND-NOTFOUND

# Testing options
# TimeOut is the amount of time in seconds to wait for processes
# to complete during testing.  After TimeOut seconds, the
# process will be summarily terminated.
# Currently set to 25 minutes
TimeOut: 1500

UseLaunchers: 
CurlOptions: 
# warning, if you add new options here that have to do with submit,
# you have to update cmCTestSubmitCommand.cxx

# For CTest submissions that timeout, these options
# specify behavior for retrying the submission
CTestSubmitRetryDelay: 5
CTestSubmitRetryCount: 3
