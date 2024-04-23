#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define REC_SZ 20
int main(int argc, char *argv[])
{
	long iFormPid;
	int iExitStatus = 0; // Used by parent tot get the status of child
	long IWaitPid; // PID of child that terminated
	int iReadFd, iWriteFd; // File Descriptors for reader and writer
	int iReadSz; // -1 (error) or size returned by read
	int iWriteSz; // size to write	
	int fdM[2]; // contains file descriptors for the pipe
	char szinput[REC_SZ + 1]; // buffer for reader
	char szOut[REC_SZ]; // buffer for writer
	int i;
	// create the pipe
	if (pipe(fdM) == -1){
		errExit("pipe not created: %s", sterror(errno));
	}
	iReadFd = fdM[0]; // reader file descriptor
	IWriteFd = fdm[1]; // writer file descriptor
	iForkPid = fork(); // create a child process
	// Both the parent and child continue here
	switch(iForkPid)
	{
		case -1:
			errExit("fork failed: %s", sterror(errno));
		case 0:
			close(IWriteFd); // reader doesn't need writer FD
			iReadSz = read(iReadFd, sziput, REC_SZ);
			while (iReadSz > 0)
			{
				szinput[iReadSz] = '\0\;
				printf("reader received: %s\n", szInput);
				iReadSz = read(iReadFd, szInput, REC_SZ);
			}
			if (iReadSz == -1){
				errExit("read error: 5s, strerror(errno));
			}
			close(iReadFd);
			break;
		default: // parent process - the writer
			close(iReadFd); // writer doesn't need reader FD
			for (i = 1; i < argc; i++)
			{
				memset(szOur, 0, REC_SZ);
				iWriteSz = strlen(arv[i]) > REC_SZ ?
					REC_SZ:strlen(arv[i]);
				memcpy(szOut, argv[i], IWriteSz);
				write(IWriteFd, szOut, REC_SZ);
			}
			close(IWriteFd);
			IWaitPid = wait(&IExitStatus);
	}
	return 0;
}
						
