Step 1:
# Configure SSH Access to GitHub

## Step 1: Generate Key Pair and Upload Public Key to GitHub

### Step 1.1: Generate Key Pair
Run the following command in your local Linux terminal to generate an SSH key pair:
```sh
ssh-keygen -t ed25519
```

### Step 1.2: Upload Public Key to GitHub
Upload the generated public key to GitHub by navigating to `Settings -> SSH and GPG keys`. Use the following command to display your public key:
```sh
cat /home/$(USER)/.ssh/id_ed25519.pub
```

### Step 1.3: Configure SSH Access
Create or edit the SSH configuration file to use the generated key:
```sh
cat > ~/.ssh/config <<EOL
Host github.com
    User git
    IdentityFile ~/.ssh/id_ed25519
EOL
```

## Step 2: Try GitHub SSH Access

### Step 2.1: Clone Repository
Clone the `gitTest` repository using SSH:
```sh
git clone git@github.com:AEJJ-Studio-2025/gitTest.git
```

### Step 2.2: Create a New Branch
Create a new branch either on the web interface or using the command line:
```sh
git branch $(USER)_test
```

### Step 2.3: Checkout the Branch
Checkout the newly created branch:
```sh
git checkout $(USER)_test
```

### Step 2.4: Coding
Create a new Python file and add the following code:
```python
cat > $(USER)_helloworld.py <<EOL
if __name__ == '__main__':
    print("Hello world from $(USER)!")
EOL
```

### Step 2.5: Add and Commit
Add and commit the new file:
```sh
git add $(USER)_helloworld.py
git commit -m "Add hello world script"
git push origin $(USER)_test
```

### Step 2.6: Create a Merge/Pull Request
Create a Merge/Pull Request and ask someone to review and approve it. Merge the branch to `main` or `master`.

### Step 2.7: Basic Git Commands Cheatsheet
Refer to the [Git Cheat Sheet](https://education.github.com/git-cheat-sheet-education.pdf) for basic Git commands.

### Step 2.8: Advanced Topics
Learn about advanced topics like pulling from the origin `main` and fixing conflicts.