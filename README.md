# GitHub Flowの練習

## 1. 目標
- Gitの基本的な操作をCLIから行うことができる
- [GitHub Flow](https://docs.github.com/ja/get-started/quickstart/github-flow)に則った開発が行えるようになる

## 3. 対象者
- `ls`, `cd`などのコマンドを用いてファイルを操作できる人
- C++ソースコードが多少なりとも読める人(高度な知識は必要ありません)

## 4. 事前準備
以下の4点を済ませておいてください。

- Gitのインストール
- エディタの準備
- makeのインストール
- 2人組の編成

### 1. Gitのインストール
  
Gitとは、バージョン管理システムの一つです。本教材で理解を目指すGitHubとは、Gitのホスティングサービス(事業者のサーバを一部貸し出すサービス)の一つです。
OSやディストリビューションに合わせてインストールしてください。

- Windows
  
  [Downloading Git](https://git-scm.com/download/win)から「Git Bash」というアプリをダウンロード・インストールしてください。

- MacOS

  標準で使うことができます。明示的にインストールしたい場合は以下のコマンドを利用してください。
  ```bash
  $ brew install git
  ```

- Linux
  
  [Download for Linux and Unix](https://git-scm.com/download/linux)を参考にディストリビューションに合わせた方法でインストールしてください。
    
> #### note
> gitがインストールできたか確認するためには、以下のコマンドを利用してください。表示のような出力となればOKです。
> ```bash
> $ git --version
> git version 2.30.1
> ```

### 2. エディタの準備

各自、テキストエディタを準備してください。

[VSCode](https://azure.microsoft.com/ja-jp/products/visual-studio-code/)を推奨しますが、宗教戦争案件なのでお好きなものをお使いください。

### 3. makeのインストール

以下のコマンドを実行してください。表示のような出力となればOKです。

```bash
$ make --version
GNU Make 3.81
Copyright (C) 2006  Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.

This program built for i386-apple-darwin11.3.0
```

以下に類する表示の場合、makeがインストールされていません。インストールしてください。

```bash
$ make --version
zsh: command not found: make
```

### 4. 2人組の編成
本教材は2人1組となって活動します。以下、Aさん,Bさんという表現をするため、どちらがどちらの役を行うか決めておいてください。

## 5. 前提知識
### 1. Gitとは？
前述の通り、Gitとはバージョン管理システムの一つです。

Gitの挙動を把握する上で、理解が必要になる用語がいくつか存在します。本節では、その中から以下の10個を概説します。

- リポジトリ
- クローン
- プル
- ワークツリー
- ステージング
- インデックス
- コミット
- プッシュ
- ブランチ
- マージ

1. **リポジトリ(Repository)**
  
    リポジトリとは、資産(ファイルやディレクトリ)を格納している貯蔵庫のことです。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/repository.png" alt="リポジトリ" title="リポジトリ">
    
    リポジトリは***リモートリポジトリ***と***ローカルリポジトリ***の2種類に分けられます。
    
    ***リモートリポジトリ***とは、Gitサーバ内に保管されているリポジトリです。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/remote-repository.png" alt="リモートリポジトリ" title="リモートリポジトリ">
    
    ***ローカルリポジトリ***とは、ユーザごとに保有するリポジトリです。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/local-repository.png" alt="ローカルリポジトリ" title="ローカルリポジトリ" style="width: 50%;">
    
    ユーザは、ローカルリポジトリ内で作業を行い、その変更をリモートリポジトリに反映させることで変更点を共有します。

2. **クローン(Clone)**
    
    クローンとは、リモートリポジトリをローカルリポジトリに複製する操作です。
    
    通常、最初のみ行います。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/clone.png" alt="クローン" title="クローン" style="width: 50%;">
    
3. **プル(Pull)**

    プルとは、リモートリポジトリにある、持っていないファイルや他の誰かが更新したファイルをローカルリポジトリに反映させる操作です。すなわち、「自分のローカル環境を共有されているものの最新版に揃える」というような認識です。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/pull-1.png" alt="プル1" title="プル1" style="width: 50%;">
    
    ---
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/pull-2.png" alt="プル2" title="プル2" style="width: 50%;">
    
    **先述のクローンはリモートリポジトリの内容を丸ごと複製するのに対し、プルは差分のみを更新します。**
    
    > topic
    > 
    > これに比べ、リモートリポジトリの最新情報の取得のみを行い、ファイルの更新を行わない操作をフェッチ(Fetch)と呼びます。
    > 本当にプルして良い状態か調べるときなどに使用します。

4. **ワークツリー(Working tree)**

    ワークツリーとは、作業しているディレクトリのことです。

5. **ステージング(Staged)**

    ステージングを理解する前に、Gitは変更を管理するファイルと管理しないファイルを指定できるということを知っておきましょう。
    
    Gitで変更を管理することを`track(追跡)`、しないことを`untrack`と呼びます。
    
    追跡されているファイルは以下の3つの状態のいずれかとなります。
    
    | 状態 | 内容 |
    | --- | --- |
    | Unmodified | 変更されていないファイル |
    | Modified | 変更されたファイル |
    | Staged | Commit対象のファイル |

    `Modified`のファイルを`Staged`の状態にすることをステージングと呼びます。ステージングされたファイルは、後述のインデックスに登録されます。

6. **インデックス(Index)**

    ワークツリーとは、作業しているディレクトリのことでした。それに対しインデックスは、ワークツリーとローカルリポジトリの中間に位置する場所です。ローカルリポジトリに反映させるファイルが格納されます。
    
    このインデックスが存在することにより、余分なファイルをコミットせずに済んだり、ファイルの一部だけの変更を記録してコミットすることができます。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/index.png" alt="インデックス" title="インデックス" style="width: 60%;">

7. **コミット(Commit)**

    インデックスの状態をローカルリポジトリに反映させる操作です。すなわち、施した編集をローカルリポジトリに記録する操作です。
    
    コミットを実行すると、編集した日時が記されたファイルやコミットごとのIDが生成されます。これらは時系列順に格納され、管理されます。
    
    > topic
    > 
    > もし「以前の状態に戻したい」という状況になった際には、このIDを指定することで、そのコミット時点の状態まで戻すことができます。
    
    コミットを実行する際に編集が記録されるファイルは、インデックスのファイルのみです。したがって、ステージングとはコミットするファイルを指定する操作であると言い換えることができます。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/commit.png" alt="コミット" title="コミット" style="width: 60%;">
        
8. **プッシュ(Push)**

    プッシュとは、ローカルリポジトリにあるファイルをリモートリポジトリに反映する操作です。
    
    ワークツリーで作業した内容をステージングによってインデックスに仮登録し、その後コミットでローカルリポジトリに反映した後、他の人へ変更を共有するためにプッシュするという流れが一般的です。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/push.png" alt="プッシュ" title="プッシュ" style="width: 60%;">
    
    > topic
    > 
    > ここまでで、図の左のユーザは無事変更点を共有することができました。右のユーザがその変更点を取得するためには、前述のプルをすればよいということになります。
    > 
    > <img src="https://github.com/Lium1126/github-practice-images/blob/master/pull-3.png" alt="プル3" title="プル3" style="width: 60%;">

9. **ブランチ(Branch)**

    ブランチとは、編集履歴を分岐させる機能です。これにより**あるブランチの編集が他のブランチに影響を及ぼさない**という状況を作ることができます。
    
    > topic
    > 
    > ブランチは、あるブランチのある時点から切り出して作成(分岐)するため、ブランチを作ることを俗に「ブランチを切る」と表現します。
    
    図は、`main`という名前のブランチから`fix/a`という名前のブランチを作成している例です。ブランチを切ると他ブランチに編集の影響を及ぼさないため、`main`ブランチは`fix/a`ブランチに加えた変更がなされません。
    
    これにより、`fix/a`ブランチは`main`ブランチから独立して開発を進めることができます。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/branch-1.png" alt="ブランチを切る" title="ブランチを切る" style="width: 50%;">

10. **マージ(Merge)**

    ブランチを分岐元となった他のブランチに併合する操作をマージと呼びます。
    
    図では、マージを行なったことにより、`main`ブランチに`fix/a`ブランチの変更が反映されました。
    
    <img src="https://github.com/Lium1126/github-practice-images/blob/master/branch-2.png" alt="マージ" title="マージ" style="width: 60%;">

## 6. ハンズオン

