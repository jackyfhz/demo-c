Step 1:
## Step 1: Add user in AWS server

```bash
sudo useradd -m -s $(which bash) -G sudo edward
sudo passwd edward
su edward
cd /home/edward
```

## Step 2: Generate key pair and configure server side

```bash
ssh-keygen -t ed25519
cat /home/edward/.ssh/id_ed25519.pub >> /home/edward/.ssh/authorized_keys
```

Copy `/home/edward/.ssh/id_ed25519` for the SSH client to use. You can either cat the file or use `scp` to transfer it.

## Step 3: Configure the Linux client

Add the id file copied from the AWS server to your client Linux `~/.ssh/` and rename it to `aws_server.key`.

```bash
scp ubuntu@15.157.97.254:/home/edward/.ssh/id_ed25519 ~/.ssh/aws_server.key
```

Or you can simply copy the content of that file and paste it to your client by using `cat`.

```bash
cat /home/edward/.ssh/id_ed25519
# Copy the text displayed
cat > ~/.ssh/aws_server.key
# Paste the text copied to clipboard
```

Change the mode to 600. Otherwise, it will report an error: `Load key "/home/jacky-fang/.ssh/aws_jackyf.key": bad permissions`.

```bash
chmod 600 ~/.ssh/aws_server.key
```

Add the AWS server to the SSH config.

```bash
cat > ~/.ssh/config <<EOL
Host 15.157.97.254
    PreferredAuthentications publickey
    IdentityFile ~/.ssh/aws_server.key
EOL
```

Test the connection.

```bash
ssh edward@15.157.97.254
```