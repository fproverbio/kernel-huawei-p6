//#include <linux/fs.h>

static struct file *open_file(char *path,int flag,int mode)
{
        struct file *fp;
        fp=filp_open(path, flag, mode);
        if (!IS_ERR_OR_NULL(fp)) return fp;
        else return NULL;
}

static int read_file(struct file *fp,char *buf,int readlen)
{
     if (fp->f_op && fp->f_op->read)
           return fp->f_op->read(fp,buf,readlen, &fp->f_pos);
     else
           return -1;
}

static int write_file(struct file *fp,char *buf,int len)
{
    if (fp->f_op && fp->f_op->write)
          return fp->f_op->write(fp, buf, len, &fp->f_pos);
    else
          return -1;
}
static int close_file(struct file *fp)
{
    filp_close(fp,NULL);
    return 0;
}

void test_write_something_to_recovery2()
{
	struct file *write_to_recovery2 = open_file("/dev/block/mmcblk0p10", O_RDWR, 0);
	
	char *buf_anclark = kmalloc(100, GFP_KERNEL);
	strcpy(buf_anclark, "AnClark! Android RAM console now works!!!!\n");
	
	set_fs(KERNEL_DS);
	write_file(write_to_recovery2, buf_anclark, strlen(buf_anclark));
	set_fs(USER_DS);

	close_file(write_to_recovery2);
}

