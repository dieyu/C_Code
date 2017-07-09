LogOK=0;
if(FATFS_LinkDriver(&SD_Driver, SDPath) == 0)
{
    if(f_mount(&SDFatFs, (TCHAR const*)SDPath, 0) == FR_OK)
    {
        if(f_open(&MyFile, "0:/LOG.TXT", FA_OPEN_ALWAYS|FA_WRITE) == FR_OK)
        {
            if(f_lseek(&MyFile,f_size(&MyFile)) == FR_OK)
            {
                if(f_write(&MyFile,s,strlen(s),(UINT*)&byteswritten) == FR_OK)
                {
                    LogOK=1;
                }
            }
            f_close(&MyFile);
        }
        f_mount(0, (TCHAR const*)SDPath, 0);
    }
    FATFS_UnLinkDriver(SDPath);
}